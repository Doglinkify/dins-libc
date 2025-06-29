#ifndef __STDIO_H__
#define __STDIO_H__

#include <stddef.h>

#define SEEK_SET 0
#define stderr 0

typedef long long FILE;

int printf(const char *, ...);
int puts(const char *);
int putchar(int);

#endif
