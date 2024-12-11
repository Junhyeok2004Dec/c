#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        *(data + i) = i * 100;
    }

    int x = 200;
    int index = -1;

    int* ptr = data;

    for(int i = 0; i <10; i++)
    {
        if(*(ptr+i) == x)
        {
            index = i;
            break;
        }
    }

    if (index != 1)
    {
        printf("월급이 200만원인 사람의 인덱스=%d\n", index);
    }
    else{printf("해당 월급을 받는 사람을 찾을 수 없습니다.\n");}
    printf("\n");

    return 0;

}