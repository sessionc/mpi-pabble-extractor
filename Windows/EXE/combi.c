#include <stdio.h>
#include <string.h>
#include "mpi.h"
#include <stdlib.h> 

#define buf_size 128

  int nprocs = -1;
  int rank = -1;
  int sendarray[100]; 
  char processor_name[128];
  int namelen = 128;
  int buf0[buf_size];
  int buf1[buf_size];
  MPI_Status status;
  MPI_Request req;
  MPI_Request req2;

void testFor1();
void testFor2();
void testWait();
void testMulti2();
void sendToItself();
void testAllCollective();
void testCollectiveOPTypeMismatch();
void testTypeMisMatch();
void testMultiSenderAndMultiRecver();
void testDiffRanksCallSameMethod();

int main (int argc, char **argv)
{
  MPI_Init (&argc, &argv);
  MPI_Comm_size ( MPI_COMM_WORLD , &nprocs);
  MPI_Comm_rank (  MPI_COMM_WORLD ,  &  rank  );
  MPI_Get_processor_name (processor_name, &namelen);

MPI_Comm comm=MPI_COMM_WORLD;

//if(rank==N/5)
if(rank==(nprocs/5))
MPI_Send (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD);

//if(rank==21)
if(rank==(nprocs/5)+1)
{
MPI_Recv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&status);
MPI_Send (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
}

//if(rank==22)
if(rank==(nprocs/5)+2)
MPI_Recv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&status);

MPI_Barrier (MPI_COMM_WORLD);


  int check;
  printf ("Checking if processor is available...");
  if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
  printf ("Executing command DIR...\n");
  check=system ("dir");
  printf ("The value returned was: %d.\n",check);


  MPI_Finalize (); 
  printf ("(%d) Finished normally\n", rank); return 0;

}


void sendToItself(){
if(rank==0){
MPI_Send (buf0, buf_size, MPI_INT, 0, 0, MPI_COMM_WORLD);

MPI_Recv (buf0, buf_size, MPI_INT, 0, 0, MPI_COMM_WORLD,&status);
}

}

void testAllCollective(){
 int count = 1000;
 int root=2;
 int *in, *out;
 MPI_Comm comm=MPI_COMM_WORLD;

if(rank==0){
MPI_Scatter( buf0, 100, MPI_INT, buf1, 100, MPI_INT, root, comm); 
MPI_Allreduce( in, out, count, MPI_INT, MPI_SUM, MPI_COMM_WORLD );
}
else{
MPI_Scatter( buf0, 100, MPI_INT, buf1, 100, MPI_INT, root, comm); 
MPI_Allreduce( in, out, count, MPI_INT, MPI_SUM, MPI_COMM_WORLD );
}

}



void testCollectiveOPTypeMismatch(){
int root=5;
MPI_Comm comm=MPI_COMM_WORLD;
if(rank==0 || rank==2){
MPI_Gather( sendarray, 100, MPI_INT, buf0, 1, MPI_INT, 0, comm); 
MPI_Reduce( buf0, buf1, 100, MPI_INT, MPI_SUM, root, comm );
}

else if(rank>=1 && rank<=6){
MPI_Gather( sendarray, 100, MPI_DOUBLE, buf0, 1, MPI_DOUBLE, 0, comm); 
//root=2;
//MPI_Reduce( buf0, buf1, 100, MPI_INT, MPI_MAX, root, comm );
MPI_Reduce( buf0, buf1, 100, MPI_INT, MPI_SUM, root, comm );
}
}


void testTypeMisMatch(){
	if(rank==0)
MPI_Send (buf0, buf_size, MPI_INT, 1, 0, MPI_COMM_WORLD);

	if(rank==1)
MPI_Recv (buf0, buf_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD,&status);
}


void testMulti2(){

for(int i=0; i<3; i++){
if(rank==i)
MPI_Isend (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req2);

if(rank==i+1)
MPI_Recv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&status);
}

}


void testMultiSenderAndMultiRecver(){
if(rank>=3 && rank<8)
for(int i=0; i<3; i++)
MPI_Isend (buf0, buf_size, MPI_INT, i, 0, MPI_COMM_WORLD, &req2);

if(rank>=0 && rank<3)
for(int i=3; i<8; i++)
MPI_Recv (buf0, buf_size, MPI_INT, i, 0, MPI_COMM_WORLD,&status);

}


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

//5.9s
void testDiffRanksCallSameMethod(){
if(nprocs>9 && nprocs<20){
if(rank==0){
//	MPI_Barrier (MPI_COMM_WORLD);
	testFor2();}
else{
	testFor2();}
} else{
MPI_Barrier (MPI_COMM_WORLD);
testFor2();}
}

void testFor2(){
for(int i=2; i<7; i++){

if(rank>=0 && rank<7)
MPI_Bcast(buf0,buf_size,MPI_INT,i,MPI_COMM_WORLD);
else
MPI_Bcast(buf0,buf_size,MPI_INT,i,MPI_COMM_WORLD);

if(rank>2 && rank <8)
MPI_Send (buf0, buf_size, MPI_INT, rank+2, 0, MPI_COMM_WORLD);

if(rank>=5 && rank<=9)
MPI_Recv (buf0, buf_size, MPI_INT, rank-2, 0, MPI_COMM_WORLD,&status);


for(int j=17; j>=0; j--){
if(rank>1 && rank <9){
MPI_Send (buf0, buf_size, MPI_INT, 1, 0, MPI_COMM_WORLD);
MPI_Recv (buf0, buf_size, MPI_INT, 1, 0, MPI_COMM_WORLD,&status);
}

if(rank==1)
for(int c=2; c<=8; c++){
MPI_Recv (buf0, buf_size, MPI_INT, c, 0, MPI_COMM_WORLD,&status);
MPI_Send (buf0, buf_size, MPI_INT, c, 0, MPI_COMM_WORLD);
}
}

}}
