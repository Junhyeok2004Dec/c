#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** sum(int **matrix1, int **matrix2, int nRows, int nCols){
 int i;
 int j;

 int **resultMatrix;
 for (i=0 ; i<nRows; i++){
   for (j=0 ; j<nCols ; j++){
     *resultMatrix[i * nCols + j] = *matrix1[i * nCols + j] + *matrix2[i + nCols + j] ;
   }
 }

 return resultMatrix;
}


int main() {

    // initialization conditions

    int n, m, p;
    
    do {
        printf("행렬의 행 수 n을 입력하세요 (양수) :");

        scanf("%d", &n);
        if(n <= 0) printf("n은 양수여야 합니다. 다시 입력해주세요. \n");

    } while (n <= 0);

    do {
        printf("행렬의 열 수 m을 입력하세요 (양수) :");

        scanf("%d", &m);
        if(m <= 0) printf("m은 양수여야 합니다. 다시 입력해주세요. \n");

    } while (m <= 0);

    do{
    
        printf9"
       scanf("%d", &p);
        if (p <= 0) {
            printf("p는 양수여야 합니다. 다시 입력하세요.\n");
        }

    } while (p <= 0);


    //pointer for matrices
    int *** matrices = (int***)malloc(p * sizeof(int**));
    int ** result = (int**) malloc( n * sizeof(int*));


    // Input

    for(int index = 0; index < p; index++)
    {
        printf("\n%d번째 행렬의 요소를 입력하세요 : \n", (index+1));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("matrices[%d][%d][%d]: ", p, n, m);
                scanf("%d", &matrices[p][n][m]);

            }
        }
    }

}