#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

    int month, days;

    printf("일수를 알고 싶은 달을 입력 하라 ");
    scanf("%d", &month);
    
    switch(month) {
        case 2:
            days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    printf("%d월은  %d 일까지 있습니다",month, days);
    


}
