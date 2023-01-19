#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    int i = 0, t = 0;
    #pragma omp parallel for schedule(static,2)
    for(i = 0; i < 20; i++){
        t = omp_get_thread_num();
        if (i % 2 == 0) printf("T %d I %d -> ", t,i);
        else printf("T %d I %d \n", t,i);
    }
    return 0;
}