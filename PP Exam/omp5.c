#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 1000, ps[1000];
    for(int i = 0; i < n; i++) ps[i] = 1;
    #pragma omp parallel for
    for(int i = 2; i < n; i++){
        for(int j = 2; j <= i / 2; j++){
            if (i % j == 0) ps[i] = 0;
        }
    }
    for(int i = 2; i < n;i++){
        if (ps[i] == 1) printf("%d \n",i);
    }
    return 0;
}