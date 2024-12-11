#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{

    int large_data[20];
    for(int i = 1; i <= 20; i++)
    {
        *(large_data+i) = i;
    }
    printf("%d \n", *(large_data + 10));

    return 0;

}