#include <stdio.h>

int main() {


    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};

    int size1 = sizeof(arr1) / sizeof(int); // 총 배열의 크기
    int size2 = sizeof(arr2) / sizeof(int); // 총 배열의 크기

    int arr3[20] = {0}; // initialization with 0

    int* ptr1 = arr1;
    int* ptr2 = arr2;
    int* ptr3 = arr3;

    int idx1 = 0, idx2 = 0, idx3 = 0;

    while(idx1 < size1 && idx2 <size2)  // 크기 비교 및 정렬 알고리즘

    {

        if(arr1[idx1] < arr2[idx2])
        {
            arr3[idx3] = arr1[idx1];
            idx1++;
        } else {
            arr3[idx3] = arr2[idx2];
            idx2++;
        }

        idx3++;
    }

    while(idx1 < size1) // 남은 값 처리
    {
        arr3[idx3] = arr1[idx1];
        idx1++;
        idx3++;
    }

    while(idx2 < size2)// 남은 값 처리
    
    {
        arr3[idx3] = arr2[idx2];
        idx2++;
        idx3++;
    }

    printf("정렬된 array B ㅣ  B | ㅁ  ");

    for(int i = 0; i < size1 + size2; i++)
    {
        printf("%d ", arr3[i]);

    }

    printf("\n12313123123123131321231312313\n");

    return 0;
}
