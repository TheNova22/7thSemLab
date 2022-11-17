#include <mpi.h>
#include<stdio.h>

int main( int argc, char* argv[] )
{
    // Init MPI
    MPI_Init( &argc, &argv);

    // Get the rank and size
    int rank, size;
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Request r,req2;MPI_Status s,s2;
    // If Master
    if( rank == 0 ){

        char* message_r1 = "Hello Rank 0";
        char buffer[256];
        MPI_Status status;
        // Send a message over tag 0
        MPI_Isend( message_r1, 13, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &r);
        MPI_Irecv( buffer, 13, MPI_CHAR, 1, 1, MPI_COMM_WORLD,  &r);
        MPI_Wait(&r,&s);
        printf("Rank : %d and Message: %s \n", rank, buffer);

    }
    else{
        char* message_r2 = "Hello Rank 1";
        // Buffer
        char buffer[256];
        MPI_Status status;
        MPI_Isend( message_r2, 13, MPI_CHAR, 0, 1, MPI_COMM_WORLD , &r);
        // Wait for your own message
        MPI_Irecv( buffer, 13, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &r);
        MPI_Wait(&r,&s);
        printf("Rank : %d and Message: %s \n", rank, buffer);

    }
    
    
    // Finalize MPI
    MPI_Finalize();

}