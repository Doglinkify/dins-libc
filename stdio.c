#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int __printf_impl_int(int val, int f) {
    if (!val) {
        if (f) {
            putchar('0');
            return 1;
        } else return 0;
    } else {
        int tmp = __printf_impl_int(val / 10, 0);
        putchar('0' + val % 10);
        return tmp + 1;
    }
}

int printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const char *p = fmt;
    int count = 0;
    while (*p) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': {
                    int i = va_arg(args, int);
                    count += __printf_impl_int(i, 1);
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*p);
                    count += 2;
                }
            }
        } else {
            putchar(*p);
            count++;
        }
        p++;
    }
    return count;
}

int puts(const char *s) {
    unsigned long len = strlen(s);
    asm volatile (
        "int $0x80"
        :
        : "a" (1), "D" (1), "S" (s), "c" (len)
    );
    putchar('\n');
    return 0;
}

int __putchar_buf;

int putchar(int c) {
    __putchar_buf = c;
    asm volatile (
        "int $0x80"
        :
        : "a" (1), "D" (1), "S" (&__putchar_buf), "c" (1)
    );
    return c & 0xff;
}
