#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>


int main()
{

    int data[10];
    int* ptr = data;
    srand(time(NULL));

    printf("채워진 배열 - ");


    for(int i = 0; i < 10; i++)
    {
        *(ptr + i) =  rand();
        printf("%d ", *(ptr + i));
    }
    
    printf("\n");

    return 0;

}