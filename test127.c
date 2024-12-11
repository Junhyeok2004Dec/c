#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
    int x, y;
    int sum, diff;
    int* sum_ptr = &sum;
    int* diff_ptr = &diff;

    printf(" 남바완 변수를 입력하라! : "); 
    scanf("%d", &x);
    printf(" 남바투 변수를 입력하라! : "); 
    scanf("%d", &y);

    *sum_ptr = x + y;
    *diff_ptr = x-y;

    printf("원소들의 합=%d\n", sum);
    printf("원소들의 차=%d\n", diff);
    
    printf("\n");

    return 0;

}