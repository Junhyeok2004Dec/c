#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

    int year;

    printf("윤년 판별 프로그램, 확인할 연도를 입력해 주십시오 => ");
    scanf("%d", &year);
    

    if((year % 4) == 0) // 4년에 한 번 씩 윤년
    {
        if(year % 100 != 0) {
            printf("%d년은 윤년입니다", year);
            return 0;
        } //  연도가 100으로 나누어 떨어지면 윤년이 아니기 때문

        if(year % 400 == 0) {
            printf("%d년은 윤년입니다", year);
            return 0;
        } // 그렇지만 400년 단위는 윤년
    }

    printf("%d년은 평년입니다", year);
    


}
