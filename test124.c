#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>


int main()
{
    double A[] = {1.23 , 3.14, 9.16, 10, 2.71828, 27.4};
    int size = sizeof(A) / sizeof(A[0]);

    double* ptr = A;
    double max = *ptr;
    double* max_ptr = ptr;


    for(int i = 0; i < size; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
            max_ptr = &max;
        }
    }

    printf("최대값은 %.2lf입니다.\n", max);
    printf("최대값이 있는 메모리 주소는 %p입니다.\n", max_ptr);


    printf("\n");

    return 0;

}