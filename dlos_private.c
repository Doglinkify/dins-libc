#include <sys/dlos_private.h>

unsigned long long dlos_sys_info(unsigned long long type) {
    unsigned long long res = 0;
    asm volatile (
        "int $0x80"
        : "=c" (res)
        : "a" (11), "D" (type)
    );
    return res;
}
