#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    int num, i;


    printf("소수를 판별해드립니다. 자연수를 입력하시죠\n ");
    scanf("%d", &num);

    if(num == 1) {
        printf("1은 판별할 수 없는 항등원입니다");
        return 0;
    }


    for(i = 2; i <= num; i++)
    {



        if((num % i) == 0) {
            printf("%d  은 합성수입니다", num);
            break;
        } else {
            printf("%d 은 소수입니다", num);
            break;
        }


        
    }



}