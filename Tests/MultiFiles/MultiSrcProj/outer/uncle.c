#include "../main/spec.h"

void testMulti2(){

for(int i=0; i<3; i++){
if(rank==i)
MPI_Isend (buf0, buf_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &req2);

if(rank==i+1)
MPI_Recv (buf0, buf_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&status);
}

}

void helloUncle(){
printf ("Hello from %s\n", "Uncle"); 

testMulti2();
}



