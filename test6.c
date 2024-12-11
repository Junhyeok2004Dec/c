#include <stdio.h>

int main()
{

    int d1, d2;

    printf("주사위 2개를 던져 합이 10이 되는 경우입니다 \n");

    for(d1 = 1; d1 <= 6; d1++) {
        for(d2 = 1; d2 <= 6; d2++) {

                if((d1 + d2) == 10) {
                    printf("1번 주사위 : %d, 2번 주사위 : %d \n", d1, d2);
                }

        }
    }

    return 0;

}