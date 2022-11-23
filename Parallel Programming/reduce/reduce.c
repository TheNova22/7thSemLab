#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, locSum = 0, globSum = 0;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    locSum += (2*rank + 2) + (2*rank + 1);
    printf("Local sum for rank %d is %d \n", rank, locSum);
    MPI_Reduce(&locSum,&globSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0){
        printf("Total sum is %d \n", globSum);
        printf("\n");
    }
    MPI_Finalize();
    
    return 0;
}