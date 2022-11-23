#include<mpi.h>
#include<stdio.h>

int main( int argc, char* argv[] )
{
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size, x = 0, buf, tot = 1, to = 0, fro = 0, fact = 1;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (rank == x){
        buf = 12;
    }
    MPI_Bcast(&buf,1,MPI_INT,x,MPI_COMM_WORLD);
    fro = (rank + 1) * buf / size;
    to = (rank) * buf / size;
    for(int i = to + 1; i <= fro; i += 1) tot *= i;
    MPI_Reduce(&tot,&fact, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    if (rank == 0){
        printf("Factorial of %d is %d\n", buf, fact);
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}