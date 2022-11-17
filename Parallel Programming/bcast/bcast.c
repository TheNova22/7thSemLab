#include<mpi.h>
#include<stdio.h>

int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, x = 0, buf;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (rank == x){
        buf = 777;
    }
    printf("Before: Buffer in %d is %d \n", rank, buf);
    MPI_Bcast(&buf,1,MPI_INT,x,MPI_COMM_WORLD);
    printf("After: Buffer in %d is %d \n", rank, buf);
    fflush(stdout);
    MPI_Finalize();
    return 0;
}