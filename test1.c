#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int x, y;

    printf(" 첫 번째 수 :: ");
    scanf("%d", &x);
    printf(" 두 번째 수 :: ");
    scanf("%d", &y);


    printf("큰 녀석 :: %d \n작은 녀석 :: %d \n", (x > y ? x : y), (x < y ? x : y));

    return 0;
}ㄴ