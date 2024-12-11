#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{

    int data[10];

    printf("배열 10개의 데이터를 입력해주세요 - ");
    for(int i = 0; i < 10; i++)
    {
        printf("data[%d] : ", i);
        scanf("%d", &data[i]);
    }

    printf("\n출력 : "); 

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);

    }

    printf("\n");

    int sum=0;
    for(int i = 0; i < 10; i++)
    {
        sum += *(data+i);
    }

    printf("배열 요소의 합 : %d", sum);

    return 0;

}