#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    MPI_Init(NULL,NULL);
    int rank, size;
    char send[100],recv[100];
    MPI_Request r,req2;MPI_Status s,s2;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if (rank == 0){
        strcpy(send,"Hello from rank 0 to 1");
        MPI_Isend(send, strlen(send)+1, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &r);
        MPI_Irecv(recv, 100, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &r);
        MPI_Wait(&r,&s);printf("This is 0: %s\n",recv);
    }
    else{
        strcpy(send,"Hello from rank 1 to 0");
        MPI_Isend(send, strlen(send)+1, MPI_CHAR, 0, 1, MPI_COMM_WORLD,&r);
        MPI_Irecv(recv, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &r);
        MPI_Wait(&r,&s);printf("This is 1: %s\n",recv);
    }
    MPI_Finalize();
    return 0;
}