#pragma once

#include "il2cpp-config.h"

#if IL2CPP_TARGET_QNX

#define IL2CPP_USES_POSIX_CLASS_LIBRARY_PAL 1

#define IL2CPP_HAVE_FUTIMENS 1

// Although dirent and dirent64 are declared with a one-byte d_name field, the structure that readdir() and readdir64() returns is allocated with enough space to hold the entire name
// https://www.qnx.com/developers/docs/7.1/index.html#com.qnx.doc.neutrino.lib_ref/topic/r/readdir.html
#define IL2CPP_HAVE_FIXED_SIZE_DIRENT 0
#define IL2CPP_HAVE_DIRENT_NAME_LEN 1
#define IL2CPP_DIRENT_MEMBER_NAME_LEN d_namelen
#define IL2CPP_HAVE_REWINDDIR 1

// QNX on 32-bit has no nsec field on stat by default
// https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/s/stat_struct.html
#if IL2CPP_SIZEOF_VOID_P == 8
#define IL2CPP_HAVE_STAT_TIM 1
#endif

#include <limits.h>
#define IL2CPP_HAVE_SYS_UN 1

#define stat_ stat
#define fstat_ fstat
#define lstat_ lstat

#include <dirent.h>

#endif // IL2CPP_TARGET_LINUX
