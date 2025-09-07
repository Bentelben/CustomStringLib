#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "mystring.h"

const size_t bufferSize = 256;

static void readLine(char *ptr) {
    assert(ptr);
    printf("enter string: ");
    scanf("%[^\n]", ptr);
    getchar();
}

int main() {
    char haystack[256] = {};
    char needle[256] = {};

    scanf("%[^\n]%*[\n]", haystack);
    scanf("%[^\n]", needle);

    printf("haystack: %s\n", haystack);
    printf("needle  : %s\n", needle);

    printf("haystack: %p\n", haystack);
    printf("mystrstr: %p\n", my_strstr(haystack, needle));
    printf("  strstr: %p\n", strstr(haystack, needle));

    return 0;
}

