#include "mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_puts(char const *str) {
    assert(str);

    while (putchar(*(str++)) != EOF);
    return putchar('\n');
}

char *my_strchr(const char *str, int c) {
    assert(str);

    do {
        if (*str == c)
            return (char *)str;
    } while (*(str++) != '\0');

    return NULL;
}

size_t my_strlen(const char *str) {
    assert(str);

    size_t i = 0;
    while (str[i++] != '\0');
    return i-1;
}

char *my_strcpy(char *dst, const char *src) {
    assert(dst);
    assert(src);

    char *tmp = dst;
    while ( (*(dst++) = *(src++)) != '\0' );
    return tmp;
}

char *my_strncpy(char *dst, const char *src, size_t n) {
    assert(dst);
    assert(src);

    char *const tmp = dst;

    size_t i = 0;
    while ( (*(dst++) = *(src++)) != '\0' && ++i < n );
    while ( ++i < n ) *(dst++) = '\0';

    return tmp;
}

char *my_strcat(char *dst, const char *src) {
    assert(dst);
    assert(src);

    my_strcpy(dst + my_strlen(dst), src);

    return dst;
}

char *my_strncat(char *dst, const char *src, size_t n) {
    assert(dst);
    assert(src);

    char *ptr = dst + my_strlen(dst);

    size_t len = my_strlen(src);
    if (len > n)
        len = n;

    my_strncpy(ptr, src, len);
    ptr[len] = '\0';

    return dst;
}

int my_atoi(const char *text) {
    assert(text);

    while (*text == ' '
        || *text == '\n'
        || *text == '\t'
        || *text == '\v') text++;

    const bool isNegative = *text == '-';
    if (*text == '-' || *text == '+')
        text++;

    int value = 0;
    for (; '0' <= *text && *text <= '9'; text++)
        value = value*10 + (*text - '0');

    return isNegative ? -value : value;
}

char *my_fgets(char *const line, const int maxline, FILE *const fp) {
    assert(line);
    assert(fp);

    if (maxline <= 1)
        return NULL;

    int c = 0;
    for (int i = 0; i < maxline-1; i++) {
        c = getc(fp);
        if (c == EOF)
            return NULL;
        line[i] = (char)c;
    }
    
    line[maxline-1] = '\0';
    return line;
}

char *my_strdup(const char *const refStr) {
    assert(refStr);

    char *dupStr = (char *)calloc(my_strlen(refStr)+1, sizeof(*dupStr));
    if (dupStr == NULL)
        return NULL;
    my_strcpy(dupStr, refStr);
    return dupStr;
}

static const size_t BUFFER_BLOCK_SIZE = 256;
ssize_t my_getline(char **const lineptr, size_t *const n) {
    if (lineptr == NULL) {
        *n = BUFFER_BLOCK_SIZE;
        *lineptr = (char *)calloc(*n, sizeof(char));
        if (*lineptr == NULL)
            return -1;
    }

    ssize_t i = 0;
    int c = 0;
    while ((c = getchar()) != '\n') {
        if (c == EOF)
            return -1;

        if ((size_t)i+1 >= *n) {
            *n += BUFFER_BLOCK_SIZE;
            *lineptr = (char *)realloc(*lineptr, *n);
            if (*lineptr == NULL)
                return -1;
        }

        (*lineptr)[i] = (char)c;
        i++;
    }

    (*lineptr)[i] = '\0'; 
    return i;
}


