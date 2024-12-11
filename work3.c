#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {


    int height;
    printf("피라미드의 줄(높이) 수를 입력하세요");
    scanf("%d", &height);

    int k = 1;
    for(int i = 1; i <= height; i++)
    {
        
        

        for(int j = 0; j <= (height*2-1)/2 - i; j++){
            printf(" ");

        }

        for(int w = 0; w < k; w++) {
            printf("*");
        }


        for(int j = 0; j <= (height*2-1)/2 - i; j++){
            printf(" ");

        }

        printf("\n");

        k+=2;

    }
}