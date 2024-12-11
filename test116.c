#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    unsigned long money;

    printf("금액을 입력하세요");

    scanf("%ld", &money);

    unsigned long num1, num2, temp;
    unsigned long m_unit[] = { 100000000, 10000, 1 };
    unsigned long m_unit01[] = { 1000, 100, 10 };
    int i, j;
    char* unit01[] = { "억", "만", "원"};
    char* unit02[] = { "천", "백", "십"};
    char* unit03[] = { " ", "일", "이", "삼", "사", "오","육", "칠", "팔", "구"};// 출력 시작 메시지
    
    printf("\n한글 금액\n\n");


    for (i = 0; i < 3; i++)
    {
        num1 = money / m_unit[i]; 

        if(!num1) {continue;}

        temp = num1; // 자릿값 저장

        for(j = 0; j < 3; j++)
        {
            num2 = num1 / m_unit01[j]; //  자릿수 출력 (한글로) - 억 만 원

            if(!num2) {continue;}

            printf("%s%s", unit03[num2], unit02[j]);      // 출력 
            num1 = num1 - num2 * m_unit01[j];

       
        }

    //마지막 자리수 출력


    printf("%s%s", unit03[num1], unit01[i]);      // 출력 
    money = money - temp * m_unit[i];

    }

    printf("\n");
    return 0;
}
