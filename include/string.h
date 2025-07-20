#ifndef __STRING_H__
#define __STRING_H__

unsigned long strlen(const char *);
char *strchr(const char *, int);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, unsigned long);
void *memmove(void *, const void *, unsigned long);
void *memcpy(void *, const void *, unsigned long);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
char *strstr(const char *, const char *);
int memcmp(const void *, const void *, unsigned long);
char *strrchr(const char *, int);
void *memset(void *, int, unsigned long);

#endif
