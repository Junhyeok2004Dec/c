#include <stdio.h>

int main() {

    float input;

    int Z; // 정수, 실수 
    float R;

    scanf("%f", &input);

    Z = *(&input);
    R = *(&input) - Z;
    //혹은
    //R = *(&input) - *(&Z); -> 부동소수점 관련 issue

    printf("정수부분 : %d, 소숫점 아래 부분 : %f", Z, R);

    

}