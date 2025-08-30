#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdlib.h>

int my_puts(const char *str);
char *my_strchr(const char *str, int c);
size_t my_strlen(const char *str);
char *my_strcpy(char *dst, const char *src);
char *my_strncpy(char *dst, const char *src, size_t n);
char *my_strcat(char *dst, const char *src);
char *my_strncat(char *dst, const char *src, size_t n);

#endif
