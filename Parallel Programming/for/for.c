#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    
    // Argv is string, convert to int using atoi
    int maxVal = atoi(argv[1]);

    // Setting the number of threads
	omp_set_num_threads(16);

    // Init a parallel for section
	#pragma omp parallel for
        for(int i = 0; i < maxVal; i++){
            // Print the value
            printf("%d from thread %d\n", i, omp_get_thread_num());
        }
	
	return 0;
}

// gcc for.c -fopenmp
// ./a.out