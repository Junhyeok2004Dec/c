#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int pc, user;

    printf("가위 바위 보 게임에 온 것을 환영한다.");
    printf("가위 바위 보 3개 중에서 하나를 선택하라 : (가위 - 0, 바위 - 1, 보 - 2)");
    scanf("%d", &user);

    pc = rand() % 3;

    printf("사용자 =  %d \n", user);
    printf("콤퓨타 =  %d \n", pc);

    if((user+1) % 3 == pc) {
        printf("콤퓨타 승리  \n");
    } else if (pc == user) {
        printf("비겼음 \n");

    } else {
        printf("승리 \n");
    }

    return 0;
}