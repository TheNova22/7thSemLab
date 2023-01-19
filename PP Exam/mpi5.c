#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    MPI_Init(NULL,NULL);
    int rank, size, n, to, fro,flag = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if (rank == 0){
        scanf("%d",&n);
    }
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    to = (rank * n) / size > 2 ? (rank * n) / size : 2;
    fro = ((rank + 1) * n) / size;
    for(int i = to + 1; i <= fro; i += 1){
        flag = 0;
        for(int j = 2; j <= i / 2; j++){
            if (i % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            printf("%d from %d \n", i, rank);
        }
    }
    MPI_Finalize();
    return 0;
}