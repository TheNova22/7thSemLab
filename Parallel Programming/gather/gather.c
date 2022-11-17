#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, sendArr[2], *rbuf;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (rank == 0){
        rbuf = (int *)malloc(size * 2 * sizeof(int));
    }
    sendArr[0] = 2*rank + 1; sendArr[1] = 2*rank + 2;
    MPI_Gather(sendArr,2,MPI_INT,rbuf,2,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Finalize();
    if (rank == 0){
        for(int i = 0; i < size*2; i ++){
            printf("%d ", rbuf[i]);
        }
        printf("\n");
    }
    return 0;
}