#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, recvArr[5], *sbuf, sumArr, tot = 0, *rbuf, sendArr[1];
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (rank == 0){
        sbuf = (int *)malloc(size * 5 * sizeof(int));
        for(int i = 0; i < 5 * size; i ++){
            sbuf[i] = i + 1;
        }
        
        rbuf = (int *)malloc(size * sizeof(int));
    }
    MPI_Scatter(sbuf,5,MPI_INT,recvArr,5,MPI_INT,0,MPI_COMM_WORLD);
    
    for(int i = 0; i < 5; i ++){
        tot += recvArr[i];
    }
    sendArr[0] = tot;
    MPI_Gather(sendArr,1,MPI_INT,rbuf,1,MPI_INT,0,MPI_COMM_WORLD);

    if (rank == 0){
        for(int i = 0; i < size; i ++){
            printf("%d ", rbuf[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}