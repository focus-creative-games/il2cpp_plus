#include "il2cpp-config.h"

#if IL2CPP_TARGET_POSIX && !RUNTIME_TINY

#include "os/TimeZone.h"

#include <sys/time.h>
#include <time.h>

// Giving a chance for external time zone warp to happen. Good for unittest
// #define DEBUGGING_TIMEZONE_WARP
// #define DEBUGGING_TIMEZONE_WARP_DELAYTIME 3000

#if IL2CPP_TARGET_QNX || (IL2CPP_TARGET_ANDROID && ENABLE_HMI_MODE)
    #ifndef HAVE_TM_GMTOFF
        #define HAVE_TM_GMTOFF
    #endif
    struct tm* localtime_safe( const time_t* timer, struct tm* buf )
    {
        return localtime_r(timer, buf);
    }
    struct tm* gmtime_safe( const time_t* timer, struct tm* buf )
    {
        return gmtime_r(timer, buf);
    }
#else
    struct tm* localtime_safe( const time_t* timer, struct tm* buf )
    {
        *buf = *localtime(timer);
        return buf;
    }
    struct tm* gmtime_safe( const time_t* timer, struct tm* buf )
    {
        *buf = *gmtime(timer);
        return buf;
    }
#endif

namespace il2cpp
{
namespace os
{
/*
 * Magic number to convert a time which is relative to
 * Jan 1, 1970 into a value which is relative to Jan 1, 0001.
 */
    const uint64_t TZ_EPOCH_ADJUST = ((uint64_t)62135596800LL);

    /*
    * Return's the offset from GMT of a local time.
    *
    *  tm is a local time
    *  t  is the same local time as seconds.
    */
    static int
    GMTOffset(struct tm *tm, time_t t)
    {
#if defined(HAVE_TM_GMTOFF)
        return tm->tm_gmtoff;
#else
        struct tm g;
        time_t t2;
        gmtime_safe(&t, &g);
        g.tm_isdst = tm->tm_isdst;
        t2 = mktime(&g);
        return (int)difftime(t, t2);
#endif
    }

    bool TimeZone::GetTimeZoneData(int32_t year, int64_t data[4], std::string names[2], bool* daylight_inverted)
    {
        struct tm start, tt;
        time_t t;

        long int gmtoff, gmtoff_start;
        int is_transitioned = 0, day;
        char tzone[64];

        /*
         * no info is better than crashing: we'll need our own tz data
         * to make this work properly, anyway. The range is probably
         * reduced to 1970 .. 2037 because that is what mktime is
         * guaranteed to support (we get into an infinite loop
         * otherwise).
         */

        memset(&start, 0, sizeof(start));

        start.tm_mday = 1;
        start.tm_year = year - 1900;

        t = mktime(&start);

        if ((year < 1970) || (year > 2037) || (t == -1))
        {
            t = time(NULL);
            localtime_safe(&t, &tt);
            strftime(tzone, sizeof(tzone), "%Z", &tt);
            names[0] = tzone;
            names[1] = tzone;
            *daylight_inverted = false;
            return true;
        }

        *daylight_inverted = start.tm_isdst;

#ifdef DO_NOT_CALCULATE_DST_FOR_GMT_AND_UTC
        // If we got here then probably there is no tz database in the system.
        // The default time zone is GMT which has no daylight saving time (same for UTC).

        localtime_safe(&t, &tt);
        strftime(tzone, sizeof(tzone), "%Z", &tt);

        if (tzone[0] == 0 || memcmp(tzone, "GMT", 3) == 0 || memcmp(tzone, "UTC", 3) == 0)
        {
            names[0] = tzone;
            names[1] = tzone;
            return true;
        }
#endif // DO_NOT_CALCULATE_DST_FOR_GMT_AND_UTC

        gmtoff = GMTOffset(&start, t);
        gmtoff_start = gmtoff;

        int prev_isdst = start.tm_isdst;

        /* For each day of the year, calculate the tm_gmtoff. */
        for (day = 0; day < 365; day++)
        {
            t += 3600 * 24;
            localtime_safe(&t, &tt);

#ifdef DEBUGGING_TIMEZONE_WARP
            if (day == 0)
                usleep(DEBUGGING_TIMEZONE_WARP_DELAYTIME);
#endif
            /* Daylight saving starts or ends here. */
            if (GMTOffset(&tt, t) != gmtoff)
            {
                /* GMT offset changed without daylight saving changes, timezone might be changed externally. 
                   Except for year before 1971, when GMT is used and UTC has not yet come into play, in which
                   case tt.tm_isdst might not be correctly reported. */
                if (prev_isdst == tt.tm_isdst && year > 1971)
                {
                    return false;
                }
                                
                struct tm tt1;
                time_t t1;
                unsigned char iteration = 0;

                /* Try to find the exact hour when daylight saving starts/ends.
                   Max iteration added to avoid infinite loop caused by external timezone changes happen during the loop. */
                t1 = t;
                const unsigned char MAX_ITERATION_HOUR = 24 + 1;
                for (iteration = 0; iteration < MAX_ITERATION_HOUR && GMTOffset(&tt1, t1) != gmtoff; iteration ++)
                {
                    t1 -= 3600;
                    localtime_safe(&t1, &tt1);
                }
                if (iteration == MAX_ITERATION_HOUR)
                    return false;

                /* Try to find the exact minute when daylight saving starts/ends.
                   Max iteration added to avoid infinite loop caused by external timezone changes happen during the loop. */
                const unsigned char MAX_ITERATION_MINUTE = 60 + 1;
                for (iteration = 0; iteration < MAX_ITERATION_MINUTE && GMTOffset(&tt1, t1) == gmtoff; iteration ++)
                {
                    t1 += 60;
                    localtime_safe(&t1, &tt1);
                }
                if (iteration == MAX_ITERATION_MINUTE)
                    return false;

                t1 += gmtoff;
                strftime(tzone, sizeof(tzone), "%Z", &tt);

                /* Write data, if we're already in daylight saving, we're done. */
                if (is_transitioned)
                {
                    if (!start.tm_isdst)
                        names[0] = tzone;
                    else
                        names[1] = tzone;

                    data[1] = ((int64_t)t1 + TZ_EPOCH_ADJUST) * 10000000L;
                    return true;
                }
                else
                {
                    if (!start.tm_isdst)
                        names[1] = tzone;
                    else
                        names[0] = tzone;

                    data[0] = ((int64_t)t1 + TZ_EPOCH_ADJUST) * 10000000L;
                    is_transitioned = 1;
                    prev_isdst = !start.tm_isdst;
                }

                /* This is only set once when we enter daylight saving. */
                if (!*daylight_inverted)
                {
                    data[2] = (int64_t)gmtoff * 10000000L;
                    data[3] = (int64_t)(GMTOffset(&tt, t) - gmtoff) * 10000000L;
                }
                else
                {
                    data[2] = (int64_t)(gmtoff_start + (GMTOffset(&tt, t) - gmtoff)) * 10000000L;
                    data[3] = (int64_t)(gmtoff - GMTOffset(&tt, t)) * 10000000L;
                }

                gmtoff = GMTOffset(&tt, t);
            }
        }

        if (!is_transitioned)
        {
            strftime(tzone, sizeof(tzone), "%Z", &tt);
            names[0] = tzone;
            names[1] = tzone;
            data[0] = 0;
            data[1] = 0;
            data[2] = (int64_t)gmtoff * 10000000L;
            data[3] = 0;
            *daylight_inverted = false;
        }

        return true;
    }
}
}

#endif
