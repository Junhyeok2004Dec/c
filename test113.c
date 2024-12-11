#include <stdio.h>

int main() {


    int i[] = {10, 20, 30, 40, 50};


    //주소를 출력
    printf("i=%d\n", i);
    printf("i=%d\n", i+1);
    

    printf("i=%d\n", *(i+0));

    printf("i+1 의 값 : %u\n", *(i+1));

    printf("*i+1 의 값 : %u\n", i[1]); 

    return 0;
}