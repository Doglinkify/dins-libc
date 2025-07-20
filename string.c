#include <string.h>

unsigned long strlen(const char *s) {
    const char *os = s;
    while (*s)
        s++;
    return s - os;
}

void *memcpy(void *dst, const void *src, unsigned long num) {
    char *cd = dst;
    const char *cs = src;
    for (int i = 0; i < num; i++)
        cd[i] = cs[i];
}

void *memmove(void *dst, const void *src, unsigned long num) {
    char *cd = dst;
    const char *cs = src;
    if (cs < cd)
        for (int i = num - 1; i >= 0; i--)
            cd[i] = cs[i];
    else
        for (int i = 0; i < num; i++)
            cd[i] = cs[i];
}

char *strcpy(char *dst, const char *src) {
    memcpy(dst, src, strlen(src));
    return dst;
}

int memcmp(const void *l, const void *r, unsigned long sz) {
    const unsigned char *cl = l;
    const unsigned char *cr = r;
    for (int i = 0; i < sz; i++) {
        if (cl[i] < cr[i])
            return -1;
        else if (cl[i] > cr[i])
            return 1;
    }
    return 0;
}

char *strcat(char *dst, const char *src) {
    memcpy(dst + strlen(dst), src, strlen(src) + 1);
    return dst;
}

char *strchr(const char *s, int c) {
    int l = strlen(s) + 1;
    for (int i = 0; i < l; i++)
        if (s[i] == c)
            return &s[i];
    return (char *)(0);
}

char *strstr(const char *s, const char *ss) {
    int l1 = strlen(s);
    int l2 = strlen(ss);
    for (int i = 0; i <= l1 - l2; i++)
        if (!memcmp(s + i, ss, l2))
            return &s[i];
    return (char *)(0);
}

int strncmp(const char *l, const char *r, unsigned long sz) {
    return memcmp(l, r, sz);
}

int strcmp(const char *l, const char *r) {
    int ll = strlen(l);
    int lr = strlen(r);
    if (lr > ll)
        ll = lr;
    return memcmp(l, r, ll + 1);
}

char *strrchr(const char *s, int c) {
    int l = strlen(s) + 1;
    for (int i = l - 1; i > -1; i--)
        if (s[i] == c)
            return &s[i];
    return (char *)(0);
}

void *memset(void *dst, int c, unsigned long sz) {
    unsigned char *cd = dst;
    for (int i = 0; i < sz; i++)
        cd[i] = c & 0xff;
    return dst;
}
