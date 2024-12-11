#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    int num, i , j;


    printf("소수를 판별해드립니다. 자연수를 입력하시죠\n ");
    scanf("%d", &num);

    printf("1부터 %d까지의 소수\n", num);

    int isprime;

    for(i = 2; i <= num; i++)
    {

        isprime = 1;

        for(j = 2; j*j <= i; j++) {
            // 
            if((i % j) == 0) {
                // 소수가 아님
                isprime = 0;
            }
        }

        if(isprime) {
            printf("%d ", i);
        }

        
    }



}