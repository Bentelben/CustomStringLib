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
    char *mybuffer = (char *)malloc(sizeof(char)*14);
    size_t myn = 0;

    ssize_t res = my_getline(&mybuffer, &myn);

    printf("%s\n", mybuffer);
    printf("%zd\n", res);

    free(mybuffer);

    return 0;
}

