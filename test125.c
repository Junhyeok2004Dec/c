#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
    double grades[] = {0, 0.5, 0.7, 1.0, 1.5, 1.7, 2.0, 2.5, 2.7, 3.0, 3.3, 3.5, 3.7, 4.0, 4.3};
    double scores[(int) (sizeof(grades) /sizeof(grades[0]))];

    int size = (int) (sizeof(grades) /sizeof(grades[0]));
    
    
    double* grades_ptr = grades;
    double* scores_ptr = scores;

    printf("grades : ");
    for(int i = 0; i < size; i++)
    {
        printf("%05.2f ",*(grades_ptr + i));    
    }
    printf("\n");

    printf("scores - ");
    for( int i = 0; i < size; i++)
    {
        *(scores_ptr + i) = 100.0 * (*(grades_ptr + i) / 4.3); // 100Á¡ È¯»ê
        printf("%05.2f ", *(scores_ptr + i)); 
    }

    printf("\n");

    return 0;

}