#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int a[100], b[100], c[100];
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
    #pragma omp parallel for
    for(int i = 0; i < 100; i++){
        c[i] = a[i] + b[i];
    }

    for(int i = 0; i < 100; i++){
        printf("%d ", c[i]);
    }
    return 0;
}