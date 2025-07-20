#include <ctype.h>

int isspace(int c) { return (c <= 13 && c >= 9) || c == 32; }

int isalnum(int c) { return isalpha(c) || isdigit(c); }

int isdigit(int c) { return c <= 57 && c >= 48; }

int iscntrl(int c) { return c <= 31 || c == 127; }

int isxdigit(int c) {
    return isdigit(c) || (c <= 70 && c >= 65) || (c <= 102 && c >= 97);
}

int isalpha(int c) { return (c <= 90 && c >= 65) || (c <= 122 || c >= 97); }
