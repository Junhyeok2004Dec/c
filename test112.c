#include <stdio.h>

int main() {


    int i = 10;

    int* pi = &i;


    printf("i=%d, pi =%p\n" , i, pi);

    (*pi)++; // 값 1 추가
    printf("i=%d, pi =%p\n" , i, pi);

    *pi++; // 포인터 1만큼 (추가)이동
    printf("i=%d, pi =%p\n" , i, pi);


    printf("i=%d, pi(data) =%d\n" , i, *pi);

}