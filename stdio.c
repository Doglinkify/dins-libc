#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int __printf_impl_int(int val, int f) {
    if (!val) {
        if (f) {
            putchar('0');
            return 1;
        } else
            return 0;
    } else {
        int tmp = __printf_impl_int(val / 10, 0);
        putchar('0' + val % 10);
        return tmp + 1;
    }
}

int __printf_impl_int_s(int val, int f, char **ddst) {
    if (!val) {
        if (f) {
            *((*ddst)++) = '0';
            return 1;
        } else
            return 0;
    } else {
        int tmp = __printf_impl_int_s(val / 10, 0, ddst);
        *((*ddst)++) = '0' + val % 10;
        return tmp + 1;
    }
}

int printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int res = vprintf(fmt, args);
    va_end(args);
    return res;
}

int vprintf(const char *fmt, va_list args) {
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
            case 's': {
                const char *s = va_arg(args, const char *);
                int l = strlen(s);
                for (int i = 0; i < l; i++)
                    putchar(s[i]), count++;
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

int sprintf(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int res = vsprintf(dst, fmt, args);
    va_end(args);
    return res;
}

int vsprintf(char *dst, const char *fmt, va_list args) {
    const char *p = fmt;
    char *ddst = dst;
    int count = 0;
    while (*p) {
        if (*p == '%') {
            p++;
            switch (*p) {
            case 'd': {
                int i = va_arg(args, int);
                count += __printf_impl_int_s(i, 1, &ddst);
                break;
            }
            case 's': {
                const char *s = va_arg(args, const char *);
                int l = strlen(s);
                for (int i = 0; i < l; i++)
                    *(ddst++) = s[i], count++;
                break;
            }
            default: {
                *(ddst++) = '%';
                *(ddst++) = *p;
                count += 2;
            }
            }
        } else {
            *(ddst++) = *p;
            count++;
        }
        p++;
    }
    return count;
}

int snprintf(char *dst, unsigned long sz, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    return vsnprintf(dst, sz, fmt, args);
}

int vsnprintf(char *dst, unsigned long sz, const char *fmt, va_list args) {
    return vsprintf(dst, fmt, args);
}

int puts(const char *s) {
    unsigned long len = strlen(s);
    asm volatile("int $0x80" : : "a"(1), "D"(1), "S"(s), "c"(len));
    putchar('\n');
    return 0;
}

int __putchar_buf;

int putchar(int c) {
    __putchar_buf = c;
    asm volatile("int $0x80" : : "a"(1), "D"(1), "S"(&__putchar_buf), "c"(1));
    return c & 0xff;
}

int getchar(void) {
    int res = 0xff;
    while (res == 0xff)
        asm volatile("int $0x80" : "=c"(res) : "a"(5));
    return res;
}
