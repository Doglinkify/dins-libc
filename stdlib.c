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
