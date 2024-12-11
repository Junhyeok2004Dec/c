#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    int numbers[10];
    int sum;

    for(int i = 0; i < 10; i++)
    {
        printf("%d 번째 숫자를 입력하여 주십시오 ",  (i+1));
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf("10개 숫자의 합은 %d 입니다", sum);

    return 0;

}