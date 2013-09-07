#include "main/spec.h"

void testWait(){

if(rank>=0 && rank<=7){
 MPI_Irecv (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req);
 MPI_Isend (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req2);
 MPI_Recv (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD,&status);

 MPI_Wait (&req, &status);
 MPI_Wait (&req2, &status);
 MPI_Wait (&req, &status);
 MPI_Wait (&req2, &status);
}

if(rank>=1 && rank<=8){
MPI_Irecv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&req);
MPI_Isend (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&req2);
MPI_Send (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD);

 MPI_Wait (&req2, &status);
 MPI_Wait (&req, &status);
 MPI_Wait (&req, &status);
 MPI_Wait (&req2, &status);
}
}

void helloParent(){
printf ("Hello from %s\n", "Parent"); 

testWait();
}




