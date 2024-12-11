#include <stdio.h>

int main() {


    int i[] = {10, 20, 30, 40, 50};

    int* p;

    p = i;

    printf("i[0]=%d, i[1]=%d, i[2]=%d, i[3]=%d, i[4]=%d\n", i[0], i[1], i[2], i[3], i[4]);
    printf("p[0]=%d, p[1]=%d, p[2]=%d, p[3]=%d, p[4]=%d\n", p[0], p[1], p[2], p[3], p[4]);
    

    p[0] = 60;
    p[1] = 70;
    p[2] = 80;

    printf("i[0]=%d, i[1]=%d, i[2]=%d, i[3]=%d, i[4]=%d\n", i[0], i[1], i[2], i[3], i[4]);
    printf("p[0]=%d, p[1]=%d, p[2]=%d, p[3]=%d, p[4]=%d\n", p[0], p[1], p[2], p[3], p[4]);
    

    return 0;
    
}