#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {


    char ss[120], rr[120], cc[120];

    int count, countSeed;

    printf("아무 숫자를 띄어쓰지 않고 그대로 입력해주세요 =>");
    scanf("%d", &countSeed);

    printf("문자열을 입력해주세요 => ");

    scanf("%[^\n]", ss);  // 개행 이전까지 입력받기 (공백 포함)

    count = strlen(ss);


    for(int i = 0; i < count; i++) {
        rr[i] = ss[count - (i+1)];

    }

    for(int i = 0; i < count; i++)
    {
        cc[i] = ss[(countSeed % (count + i * i))];
    }
    
    rr[count] = '\0';
    

    printf("%s을 반대로 하면? %s\n", ss, rr);
    printf("%s는 크레이지 %s", ss, cc);
    

}