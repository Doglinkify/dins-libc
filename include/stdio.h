#ifndef __STDIO_H__
#define __STDIO_H__

#include <stddef.h>
#include <stdarg.h>

#define SEEK_SET 0
#define stderr ((FILE *)114514)

typedef long long FILE;

int printf(const char *, ...);
int vprintf(const char *, va_list);
int sprintf(char *, const char *, ...);
int vsprintf(char *, const char *, va_list);
int snprintf(char *, unsigned long, const char *, ...);
int vsnprintf(char *, unsigned long, const char *, va_list);
int puts(const char *);
int putchar(int);
int getchar(void);

#endif
