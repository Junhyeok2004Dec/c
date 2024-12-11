#include <stdio.h>

int main() {

    int sum = 0;

    for(int i=1; i <= 10000; i++)
    {
        if( (i%15)==0 ) {
            sum+=i;
        }
    }

printf("1부터 10000까지의 15의 배수의 합: %d\n", sum);

}