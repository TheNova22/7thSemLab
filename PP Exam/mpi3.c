#include<mpi.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int main(){
    MPI_Init(NULL,NULL);
    srand(time(NULL));
    int rank, size;
    int *a,*b,*c, n = 100;
    int mini, i, *ma,*mb, *mc;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    mini = n / size;
    ma = (int *) malloc(mini * sizeof(int));
    mb = (int *) malloc(mini * sizeof(int));
    mc = (int *) malloc(mini * sizeof(int));
    if (rank == 0){
        a = (int *) malloc(n * sizeof(int));
        b = (int *) malloc(n * sizeof(int));
        c = (int *) malloc(n * sizeof(int));
        for(i = 0; i < n; i++){
            a[i] = rand() % 100;
            b[i] = rand() % 100;
        }
    }
    MPI_Scatter(a, mini, MPI_INT, ma, mini, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(b, mini, MPI_INT, mb, mini, MPI_INT, 0, MPI_COMM_WORLD);
    for(int i = 0; i < mini;i++){
        mc[i] = ma[i] + mb[i];
    }
    MPI_Gather(mc,mini,MPI_INT,c,mini,MPI_INT,0,MPI_COMM_WORLD);
    if (rank == 0){
        for(i = 0; i < n; i++){
            printf("%d ", c[i]);
        }
    }
    MPI_Finalize();
    return 0;
}