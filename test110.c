#include <stdio.h>

int main() {


    int a = 5, b = 10;

    printf("변경 전 : a = %d, b = %d", a, b);

    int* ptr_a = &a;
    int* ptr_b = &b;

    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;


    printf("변경  후 : a = %d, b = %d", a, b); 

    return 0;
}