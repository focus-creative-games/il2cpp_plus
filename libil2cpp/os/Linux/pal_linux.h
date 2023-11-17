#pragma once

#include "il2cpp-config.h"

#if IL2CPP_TARGET_LINUX

#define IL2CPP_USES_POSIX_CLASS_LIBRARY_PAL 1

#define IL2CPP_HAVE_GNU_STRERROR_R 1
#define IL2CPP_HAVE_STAT_FLAGS 1
#define IL2CPP_HAVE_STAT_FLAGS 1
#define IL2CPP_HAVE_LCHFLAGS 1
#define IL2CPP_HAVE_FUTIMENS 1
#define IL2CPP_HAVE_FIXED_SIZE_DIRENT 1
#define IL2CPP_HAVE_REWINDDIR 1

#define IL2CPP_HAVE_STAT_TIM 1
#include <sys/sendfile.h>
#include <limits.h>
#define IL2CPP_HAVE_SENDFILE_4 1
#define IL2CPP_HAVE_SYS_UN 1

#define stat_ stat
#define fstat_ fstat
#define lstat_ lstat

#include <dirent.h>

#endif // IL2CPP_TARGET_LINUX
