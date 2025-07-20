#include <stdlib.h>

void _fini(void);

void exit(int _status) {
    _fini();
    asm volatile (
        "int $0x80"
        :
        : "a" (4)
    );
    __builtin_unreachable();
}

void free(void *_p) {}

unsigned long long __dlos_brk = 0;

void *malloc(unsigned long size) {
    if (!__dlos_brk)
        asm volatile (
            "int $0x80"
            : "=S" (__dlos_brk)
            : "a" (7), "D" (0)
        );
    void *res = 0;
    asm volatile (
        "int $0x80"
        : "=S" (res)
        : "a" (7), "D" (__dlos_brk + size + 4096)
    );
    __dlos_brk += size + 4096;
    return res;
}

void *realloc(void *p, unsigned long _sz) {
    return p;
}
