#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{

    int arr[5], index;
    int* p = arr;

    printf("5개의 정수 데이터를 입력해주세요 - ");
    scanf("%d %d %d %d %d", p, p+1, p+2, p+3, p+4); // 이미 p는 포인터 주소를 가르키기에, &을 붙이지 않는다.

    printf("reverse : ");

    for(int i = 0; i < 5; i++)
    {
        printf(" %d", *(p+4-i));
    }

    
    printf("\n");

    return 0;

}