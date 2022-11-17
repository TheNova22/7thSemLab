#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, recvArr[2], *sbuf;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (rank == 0){
        sbuf = (int *)malloc(size * 2 * sizeof(int));
        for(int i = 0; i < 2 * size; i ++){
            sbuf[i] = i + 1;
        }
    }
    MPI_Scatter(sbuf,2,MPI_INT,recvArr,2,MPI_INT,0,MPI_COMM_WORLD);
    
    printf("For process %d \n", rank);
    for(int i = 0; i < 2; i ++){
        printf("%d ", recvArr[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}