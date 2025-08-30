#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "mystring.h"

bool test_strchr(const char *const str, const char c);
bool test_strlen(const char *const str);
bool test_strcpy(const char *const str);
bool test_strncpy(const char *const str, const size_t n);
bool test_strcat(const char *const str1, const char *const str2);
bool test_strncat(const char *const str1, const char *const str2, const size_t n);

const size_t bufferSize = 256;

int main() {
    char str1[100];
    char str2[100];
    char c = 0;
    size_t n = 3;
    
    if (scanf("%[^\n]%*[\n]", str1) != 1)
        return -1;
    if (scanf("%[^\n]%*[\n]", str2) != 1)
        return -1;
    if (scanf("%zu", &n) != 1)
        return -1;

    my_puts(str1);
    puts(str1);

    printf("\n");

    printf("strchr  %d\n", test_strchr(str1, c));
    printf("strlen  %d\n", test_strlen(str1));
    printf("strcpy  %d\n", test_strcpy(str1));
    printf("strncpy %d\n", test_strncpy(str1, n));
    printf("strcat  %d\n", test_strcat(str1, str2));
    printf("strncat %d\n", test_strncat(str1, str2, n));

    return 0;
}

static void printBuffer(char buffer[]) {
    for (size_t i = 0; i < bufferSize; i++)
        if (buffer[i]=='\0') printf("_");
        else printf("%c", buffer[i]);
    printf("\n");
}

static bool compareBuffers(char buffer1[], char buffer2[]) {
    for (size_t i = 0; i < bufferSize; i++) {
        if (buffer1[i] != buffer2[i]) {
            printBuffer(buffer1);
            printBuffer(buffer2);
            return false;
        }
    }

    return true;
}


bool test_strchr(const char *const str, const char c) {
    return my_strchr(str, c) == strchr(str, c);
}

bool test_strlen(const char *const str) {
    return my_strlen(str) == strlen(str);
}

bool test_strcpy(const char *const str) {
    char buffer1[bufferSize] = "";
    char buffer2[bufferSize] = "";

    my_strcpy(buffer1, str);
    strcpy(buffer2, str);

    return compareBuffers(buffer1, buffer2);
}

bool test_strncpy(const char *const str, size_t n) {
    char buffer1[bufferSize] = "";
    char buffer2[bufferSize] = "";

    my_strncpy(buffer1, str, n);
    strncpy(buffer2, str, n);

    return compareBuffers(buffer1, buffer2);
}

bool test_strcat(const char *const str1, const char *const str2) {
    char buffer1[bufferSize] = "";
    strcpy(buffer1, str1);

    char buffer2[bufferSize] = "";
    strcpy(buffer2, str1);


    my_strcat(buffer1, str2);
    strcat(buffer2, str2);

    return compareBuffers(buffer1, buffer2);
}

bool test_strncat(const char *const str1, const char *const str2, size_t n) {
    char buffer1[bufferSize] = "";
    strcpy(buffer1, str1);

    char buffer2[bufferSize] = "";
    strcpy(buffer2, str1);

    assert(compareBuffers(buffer1, buffer2));

    my_strncat(buffer1, str2, n);
    strncat(buffer2, str2, n);

    return compareBuffers(buffer1, buffer2);
}

