#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    int n = 30,i;
    omp_set_num_threads(10);
    #pragma omp parallel for schedule(static,2)
    for(i=1; i<=n; i++){
        int t = omp_get_thread_num();
        printf("%d : %d \n", t, i);
    }
    return 0;
}