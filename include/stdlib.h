#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <stddef.h>

void exit(int);
void free(void *);
void *malloc(unsigned long);
void *realloc(void *, unsigned long);
void *memset(void *, int, unsigned long);

#endif
