#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc){
    // Setting the number of threads
	omp_set_num_threads(16);

    // New variable
    int x = 20;

    // Init a parallel for section
	#pragma omp parallel for private(x)
        for(int i = 0; i < 10; i++){
            x = i;
            // Print the value
            printf("x:%d from thread %d\n", x, omp_get_thread_num());
        }
	
    printf("x is %d \n", x);
	return 0;
}

// gcc priv.c -fopenmp
// ./a.out