#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i = 0, j = 0;
    float pi = 0, t[8], temp;
    omp_set_num_threads(8);
    #pragma omp parallel for
    for(i = 0; i < 25000; i++){
        #pragma omp critical
        {
        temp = 1.0 / (2*(float)i + 1);
        if (i % 2 != 0) temp *= -1;
        pi += temp;
        }
        // printf("%d %f \n",i,temp);
    }
    // for(i = 0;i < 8; i++){
    //     pi += t[i];
    // }
    printf("%f \n", pi * 4);
}