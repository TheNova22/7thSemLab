#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define NUM_THREADS 4

static long num = 100000;
double step;

int main(){
    int i;
    // Set number of threads
    omp_set_num_threads(NUM_THREADS);
    double x,pi,sum[NUM_THREADS];
    step = 1.0 / (double) num;

    // Create a multi-threaded process
    #pragma omp parallel private(i,x)
    {
        // Run based on id
        int id = omp_get_thread_num();
        // Using formula, caclulate the next precise value
        for(i = id, sum[id] = 0.0; i < num; i += NUM_THREADS){
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + (x*x));
        }
    }
    // Sum all up
    for(i = 1; i < NUM_THREADS; i++){
        sum[0] += sum[i];
    }
    pi = sum[0] / num;
    printf("pi = %6.12f \n", pi);
    return 0;
}