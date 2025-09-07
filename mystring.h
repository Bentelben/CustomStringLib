#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>

int my_puts(const char *str);
char *my_strchr(const char *str, int c);
size_t my_strlen(const char *str);
char *my_strcpy(char *dst, const char *src);
char *my_strncpy(char *dst, const char *src, size_t n);
char *my_strcat(char *dst, const char *src);
char *my_strncat(char *dst, const char *src, size_t n);
int my_atoi(const char *text);
char *my_strdup(const char *text);
char *my_fgets(char *line, int maxline, FILE *fp);
ssize_t my_getline(char **lineptr, size_t *n, FILE *file);
char *my_strstr(const char * haystack, const char *needle);

#endif
