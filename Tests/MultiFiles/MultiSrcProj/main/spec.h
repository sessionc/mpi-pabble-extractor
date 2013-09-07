#ifndef spec_H
#define spec_H

#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <stdlib.h> 

 #define buf_size 128
  int buf0[buf_size];
  int buf1[buf_size];
   MPI_Status status;
   MPI_Request req;
   MPI_Request req2;

 extern  int nprocs;
 extern  int rank;
 extern  int sendarray[100]; 
 extern  char processor_name[128];
 extern  int namelen;

void helloUncle();
void helloSib();
void helloParent();
void helloChild();


#endif
