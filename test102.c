// 사용자로부터 5개의 정수를 입력받아서 배열에 저장한 후, 배열에서 최대값과 최소값을 계산하여 출력하는 코드 작성
#include <stdio.h>

int main() {
    int var[5];

    int max = -2147483648;
    int min = 2147483647;

    

    printf("정수 5개를 입력해주세요 \n");

    for(int i = 0; i < 5; i++   )
    {
        printf("정수 %d :: ", (i+1));
        scanf("%d", &var[i]);

        if(var[i] > max) {
            max = var[i];
        }

        if(var[i] < min)
        {
            min = var[i];
        }
        
    }

    printf("입력한 정수들 중의 최대값은 %d 입니다\n", max);
    printf("입력한 정수들 중의 최솟값은 %d 입니다\n", min);

    return 0;
}
