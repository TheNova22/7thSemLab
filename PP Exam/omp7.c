#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int tot = 0;
    #pragma omp parallel for shared(tot)
    for(int i = 0; i <= 100; i++){
        #pragma omp critical
        {
            tot += i;
        }
    }
    printf("%d \n", tot);
    return 0;
}