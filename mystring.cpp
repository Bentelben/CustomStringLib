#include "mystring.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_puts(char const *str) {
    assert(str);

    while (*str != '\0' && putchar(*(str++)) != EOF);

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
    while (str[i] != '\0') 
        i++;
    return i;
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

    my_strncpy(ptr, src, n);

    return dst;
}

int my_atoi(const char *text) {
    assert(text);

    while (isspace(*text)) text++;

    const bool isNegative = (*text == '-');
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
    int i = 0;
    for (; c != '\n' && i < maxline-1; i++) {
        c = getc(fp);
        if (c == EOF)
            return NULL;
        
        line[i] = (char)c;
    }
    
    line[i] = '\0';
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
ssize_t my_getline(char **const lineptr, size_t *const n, FILE *const file) {
    assert(lineptr);
    assert(n);
    assert(file);

    if (*lineptr == NULL) {
        *n = BUFFER_BLOCK_SIZE;
        *lineptr = (char *)calloc(*n, sizeof(char));
        if (*lineptr == NULL)
            return -1;
    }

    ssize_t i = 0;
    int c = 0;

    do {
        c = getc(file);
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
    } while (c != '\n');

    (*lineptr)[i] = '\0'; 
    return i;
}

static bool compareNeedle(const char **const haystack, const char *const needle) {
    size_t i = 0;
    for (; (*haystack)[i] != '\0' && needle[i] != '\0' && (*haystack)[i] == needle[i]; i++);

    if (needle[i] == '\0')
        return true;

    //*haystack += i;

    return false;
}

char *my_strstr(const char * haystack, const char *const needle) {
    for (; *haystack != '\0'; haystack++) {
        if (compareNeedle(&haystack, needle))
            return (char *)haystack;
    }

    return NULL;
}
