#include "spec.h"


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

void testDiffRanksCallSameMethod(){
if(nprocs>9 && nprocs<20){
if(rank==0){
	testFor2();}
else{
	testFor2();}
} else{
MPI_Barrier (MPI_COMM_WORLD);
testFor2();}
}



void helloSib(){
printf ("Hello from %s\n", "Sibling1"); 

testDiffRanksCallSameMethod();

}
