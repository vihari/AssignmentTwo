/*
 * File:     mpi_outlab.c
 * Input:
 *    A:     elements of two dimentional array (optional)
 * Output:
 *    A:     sequence of integers indicating the columns of
 *           two dimentional array having fastest path
 *
 * Compile:  mpicc -g -Wall -o mpi_outlab mpi_outlab.c
 * Run:
 *    mpiexec -n <p> mpi_outlab <r> <c> <g|i> <matrix> 
 *       - p: the number of processes
 *		 - r: number of rows of the matrix
 *		 - C: number of columns of the matrix
 *       - g: generate random, two dimensional matrix
 *       - i: user will input two dimensional matrix
 *       - matrix: r*c elements of the matrix
 *
 * Notes:
 * 1.  c must be evenly divisible by p
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

void srandom(unsigned int seed);
long int random(void);
const int RMAX = 100;

/* Local functions */
void Usage(char* program);   // proc 0 part of Get args


/* -----------------------------------------------------------------
 * Purpose, args, output: same as Get_args function in mpisort.c
 */
void Get_args(int argc, char* argv[], int* global_n_p, int* local_n_p,
	      char* gi_p, int my_rank, int p, int* r, int* c, MPI_Comm comm);

/*-------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
  int my_rank, p;
  char g_i;
  int global_n;
  int local_n;
  int r, c;
  MPI_Comm comm;

  MPI_Init(&argc, &argv);
  comm = MPI_COMM_WORLD;
  MPI_Comm_size(comm, &p);
  MPI_Comm_rank(comm, &my_rank);

  Get_args(argc, argv, &global_n, &local_n, &g_i, my_rank, p, &r, &c, comm);
  /*Your code goes here*/
  
  MPI_Finalize();

  return 0;
}  /* main */


/*-------------------------------------------------------------------
 * Function:  Usage
 * Purpose:   Print command line to start program
 * In arg:    program:  name of executable
 * Note:      Purely local, run only by process 0;
 */
//mpiexec -n <p> mpi_outlab <r> <c> <g|i> <matrix> 
void Usage(char* program) {
   fprintf(stderr, "usage:  mpiexec -n <p> %s <r> <c> <g|i> <matrix>\n",
       program);
   fprintf(stderr, "   - p: the number of processes \n");
   fprintf(stderr, "   - r: rows of the matrix \n");
   fprintf(stderr, "   - c: columns of the matrix \n");
   fprintf(stderr, "   - g: generate random, two dimensional matrix\n");
   fprintf(stderr, "   - i: user will input two dimensional matrix\n");
   fprintf(stderr, "   - matrix: r*c elements of the matrix");
   fprintf(stderr, " ( c must be evenly divisible by p)\n");
   fflush(stderr);
}  /* Usage */
