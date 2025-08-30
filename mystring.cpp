#include "mystring.h"

#include <stdio.h>

int my_puts(const char *str) {
    return printf("%s\n", str);
}

char *my_strchr(const char *str, int c) {
    do {
        if (*str == c)
            return (char *)str;
    } while (*(str++) != '\0');

    return NULL;
}

size_t my_strlen(const char *str) {
    size_t i = 0;
    while (str[i++] != '\0');
    return i-1;
}

char *my_strcpy(char *dst, const char *src) {
    char *tmp = dst;
    while ( (*(dst++) = *(src++)) != '\0' );
    return tmp;
}

char *my_strncpy(char *dst, const char *src, size_t n) {
    char *tmp = dst;

    size_t i = 0;
    while ( (*(dst++) = *(src++)) != '\0' && i++ < n );
    while ( i++ < n ) *(dst++) = '\0';

    return tmp;
}

char *my_strcat(char *dst, const char *src) {
    my_strcpy(dst + my_strlen(dst), src);

    return dst;
}

char *my_strncat(char *dst, const char *src, size_t n) {
    char *ptr = dst + my_strlen(dst);

    size_t len = my_strlen(src);
    if (len > n) len = n;

    my_strncpy(ptr, src, len);
    ptr[len] = '\0';

    return dst;
}



