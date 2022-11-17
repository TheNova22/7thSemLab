#include<mpi.h>
#include<stdio.h>

int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, x = 0;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    for(int i = 0; i < 100; i++){
        x += i;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    printf("Hello World from %d and p %d \n", rank, size);
    fflush(stdout);
    MPI_Finalize();
    return 0;
}