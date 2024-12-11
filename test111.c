#include <stdio.h>

int main() {


    char* c;
    int* i;
    double* d;


    c = (char*)1000; //  1000 林家
    i = (int*)1000; //  1000 林家
    d = (double*)1000; //  1000 林家


    printf("c=%u, c+1=%u, c+2=%u\n", c, c + 1, c + 2);
    printf("i=%u, i+1=%u, i+2=%u\n", i, i + 1, i + 2);
    printf("d=%u, d+1=%u, d+2=%u\n", d, d + 1, d + 2);

    return
}