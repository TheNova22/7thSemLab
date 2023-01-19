#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    MPI_Init(NULL,NULL);
    int rank, size;
    char msg[100];
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if (rank == 0){
        strcpy(msg,"Hello from rank 0 to 1");
        MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
    }
    else{
        MPI_Recv(msg, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%s\n",msg);
    }
    MPI_Finalize();
    return 0;
}