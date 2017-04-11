#ifndef __SYS_LOG_H
#define __SYS_LOG_H

#include "stdarg.h"

#define SYS_LOG_LEVEL_OFF 0
#define SYS_LOG_LEVEL_ERROR 1
#define SYS_LOG_LEVEL_WARNING 2
#define SYS_LOG_LEVEL_INFO 3
#define SYS_LOG_LEVEL_DEBUG 4

#if !defined(SYS_LOG_LEVEL)
/* Use default */
#define SYS_LOG_LEVEL CONFIG_SYS_LOG_DEFAULT_LEVEL
#elif (SYS_LOG_LEVEL < CONFIG_SYS_LOG_OVERRIDE_LEVEL)
/* Use override */
#undef SYS_LOG_LEVEL
#define SYS_LOG_LEVEL CONFIG_SYS_LOG_OVERRIDE_LEVEL
#endif

typedef void (*out_func_t)(char c);

void _vprintk(out_func_t out, const char *fmt, va_list ap);

#endif
