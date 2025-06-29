#include <string.h>

unsigned long strlen(const char *s) {
    const char *os = s;
    while (*s) s++;
    return s - os;
}
