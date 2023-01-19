#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int fibo(int n){
    if (n < 2){
        return n;
    }
    int a = 0, b = 0;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            a = fibo(n - 1);
        }

        #pragma omp section
        {
            b = fibo(n - 2);
        }
    }
    return a + b;
}
int main(){
    int i = 0, t = 0;
    #pragma omp parallel for schedule(static)
    for(i = 0; i < 30; i++){
        printf("%d %d \n", i, fibo(i));
    }
    return 0;
}