#define _CRT_SECURE_NO_WARNINGS

int main() {


    int data[5];
    int max = -2147483648;
    int* max_p = &max;
    printf("5개의 숫자를 입력하세요 \n");

            
    for (int i = 0; i < 5; i++)
        {

            printf("%d 번째 숫자 : ", i+1);
            
            scanf("%d", data+i);

            if(*(data+i) > max)
            {
                max = *(data+i);
                max_p = &max;
            }
        }

        printf("가장 큰 숫자는 %d 입니다.", *max_p);// (굳이 포인터를 안 사용하여도 되지만 포인터를 연습하기 위 hayo)

        return 0;
}
