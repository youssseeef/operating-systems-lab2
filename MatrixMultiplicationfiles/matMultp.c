#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* number of matrix columns and rows */
#define X 3
#define Y 4
#define Z 5

int A[X][Y];
int B[Y][Z];
int C[X][Z];

/*** functions for non threaded multiplications ****/
int dotProduct(int r, int c)
// r and c are the row and coloumn of matrices A and B, respectively
{
	printf("dotProduct function is not implemented yet\n");
	// Calculate the dot product of the row r from A with the column c from B
	
}
void nonThreadedMatMult()
{
	printf("nonThreadedMatMult function is not implemented yet\n");
	// Loop over every point in the matrix C and calculate it by calling
	// the dot product fuction
	
	// Print the elements of C
}


/*** functions for threaded element multiplications ****/

struct thread_data
{
	// You may need this fill this struct to pass and receive data from 
	// threads
};
struct thread_data thread_data_array[X*Z];

void *dotProductThreadElem(void *threadArgs)
// Element by element threaded calculation
{
	// Exctract the passed arguments from the threadArgs structure

	// Calculate the dotProduct

	// Exit the thread
}

void threadedMatMultPerElement()
{
	printf("threadedMatMultPerElement function is not implemented yet\n");
	pthread_t threads[X*Z];

	// Create X*Z threads and pass the appropriate threadArgs to it

	// Join the X*Z threads

	// Print the elements of C	
}

/*** functions for threaded row multiplications ****/
// Similar to the element multiplication but only X threads are created

void threadedMatMultPerRow()
{
	printf("threadedMatMultPerRow function is not implemented yet\n");
}

int main(int argc, char *argv[])
{
	int i, j;
	for (i= 0;i<X;++i)
		for (j= 0;j<Y;++j)
			A[i][j] = i * Y + j;
	for (i= 0;i<Y;++i)
		for (j= 0;j<Z;++j)
			B[i][j] = i * Z + j;

	nonThreadedMatMult();
	threadedMatMultPerElement();
	threadedMatMultPerRow();
	
	return 0;
}
