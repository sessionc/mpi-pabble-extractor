#include "../spec.h"

void testMultiSenderAndMultiRecver(){
if(rank>=3 && rank<8)
for(int i=0; i<3; i++)
MPI_Isend (buf0, buf_size, MPI_INT, i, 0, MPI_COMM_WORLD, &req2);

if(rank>=0 && rank<3)
for(int i=3; i<8; i++)
MPI_Recv (buf0, buf_size, MPI_INT, i, 0, MPI_COMM_WORLD,&status);

}



void helloChild(){
	
printf ("Hello from %s\n", "child"); 

testMultiSenderAndMultiRecver();

}



