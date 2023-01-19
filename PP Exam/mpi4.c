#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    MPI_Init(NULL,NULL);
    int rank, size, n, to, fro, tot = 1, fact = 1;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if (rank == 0){
        n = 12;
    }
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    to = (rank * n) / size;
    fro = ((rank + 1) * n) / size;
    for(int i = to + 1; i <= fro; i += 1){
        tot *= i;
    }
    MPI_Reduce(&tot,&fact,1,MPI_INT,MPI_PROD,0,MPI_COMM_WORLD);
    if (rank == 0){
        printf("F of %d is %d \n",n,fact);
    }
    MPI_Finalize();
    return 0;
}