#include <stdio.h>
#include <string.h>
#include "mpi.h"
#include <stdlib.h> 

#define buf_size 128

  int nprocs = -1;
  int rank = -1;
  int sendarray[100]; 
  int buf0[buf_size];
  int buf1[buf_size];
  MPI_Status status;
  MPI_Request req;
  MPI_Request req2;

int main (int argc, char **argv)
{
  MPI_Init (&argc, &argv);
  MPI_Comm_size ( MPI_COMM_WORLD , &nprocs); /*nprocs=100*/
  MPI_Comm_rank ( MPI_COMM_WORLD , &rank);

if(rank==0){
	MPI_Isend (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req);

	MPI_Wait (&req, &status);
	
	MPI_Irecv (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req2);
}

if(rank==1){
	MPI_Isend (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&req2);

	MPI_Wait (&req2, &status);
	
	MPI_Irecv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&req);
}

MPI_Barrier (MPI_COMM_WORLD);
MPI_Finalize (); 
}