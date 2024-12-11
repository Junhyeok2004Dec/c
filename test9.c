#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>// 표준 입출력 함수 사용을 위해 사용
#include<stdlib.h>// 난수 생성 함수 srand(), rand()를 사용하기 위해 사용
#include<time.h>// 시간 기반으로 난수를 생성하기 위해 사용

int main() 
{

    float n1, n2, ans;

    char operator[] = {'+', '-', 'x', '/'} ;

    int questLine;

    srand(time(NULL)) ;

    printf("생성할 사칙연산 문항 수를 입력하세요 => ");
    scanf("%d", &questLine);

    for(int i = 0; i < questLine; i++) {
        n1 = rand() % 1000 + 1; // 1~1000
        n2 = rand() % 1000 + 1;

        char operator_ = operator[rand() % 4]; // 4개 연산자 중 랜덤

        if(operator_ == '/')
        {
            if((int) n1 % (int) n2 != 0) {
                i--;
                continue;
            }
        }

        printf("문제 %d: %.2f %c %.2f = ?\n", i + 1, n1, operator_, n2);  // 문제 출력
        printf("정답을 입력하세요: "); 
        scanf("%f", &ans);

        float correct_ans;
        switch(operator_){

            case '+':
                correct_ans = n1 + n2;
                break;
            case '-':
                correct_ans = n1 - n2;
                break;
            case 'x':
                correct_ans = n1 * n2;
                break;
            case '/':
                correct_ans = (float) n1 / n2;
                break;
            default:
                printf("잘못된 입력입니다. 프로그램을 종료합니다");
                return -99;
        }

        if(ans == correct_ans)
        {
            printf("정답!");
        } else {
            printf("오답! 정답은 바로 %.2f 입니다", correct_ans);
        }





    }


}