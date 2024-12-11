#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
		
    char res;
    printf("당신의 학점은 (A, B, C, D, F) 중에 무엇인가요? ");

    scanf("%c", &res);
    
    switch(res)
    {
        case 'A':
            printf("우수합니다! 잘하셨어요!") ;
            break;
        case 'B':
            printf("잘했습니다. 지속적인 노력이 필요해욘.");
            break;
        case 'C':
            printf("평균적인 성적입니다. 노력이 필요할 것 같아요.");
            break;
        case 'D':
            printf("합격은 했지만, 더 많은 노력이 필요합니다.");
            break;

        case 'F':

            printf("좀 더 노력해야 할 것 같아요. 화이팅!"); 
            break;
        
    }


}