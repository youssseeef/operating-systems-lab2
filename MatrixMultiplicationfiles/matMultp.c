```#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* number of matrix columns and rows */
#define X 2
#define Y 3
#define Z 2

int A[X][Y] = {{1,2,3},{4,5,6}};
int B[Y][Z] = {{7,8},{9,10},{11,12}};
int C[X][Z];




/*** functions for non threaded multiplications ****/
int dotProduct(int r, int c)
// r and c are the row and coloumn of matrices A and B, respectively
{
    //printf("dotProduct function is not implemented!\n");
    // Calculate the dot product of the row r from A with the column c from B

    int i, sum = 0;
    // loop over the rows of A and the columns of B
    for(i = 0; i < Y; i++) {
        //printf("%d \n", B[0][0] );
        sum += (A[r][i] * B[i][c]);
    }
    return sum;
}
void nonThreadedMatMult()
{
    //printf("nonThreadedMatMult function is not implemented yet\n");
    int i,j =0;
    for(i =0; i<X; i++){
        for(j =0; j<Y; j++){
            C[i][j] = dotProduct(i,j);
            printf("%d\n",C[i][j]);
        }
    }
    //printf("%d\n ", dotProduct(0, 0));
    // Loop over every point in the matrix C and calculate it by calling
    // the dot product fuction

    // Print the elements of C
}


/*** functions for threaded element multiplications ****/

struct thread_data
{
    // You may need this fill this struct to pass and receive data from
    // threads
    //output row;
    int row;
    //output column;
    int column;
    //value of row
    int value;
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
	pthread_attr_t attr;
	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("threadedMatMultPerElement function\n");
    pthread_t threads[X*Z];

    int i = 0;
    for(int i = 0; i < X*Z ; i++){
         error = pthread_create(&threads[i], &attr, dotProductThreadElem, (void *)threadArgs);
       if (error) {
          printf("ERROR; return code from pthread_create() is %d\n", error);
          exit(-1);
          }
    }

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
    // int i, j;
    // for (i= 0;i<X;++i)
    //     for (j= 0;j<Y;++j)
    //         A[i][j] = i * Y + j;
    // for (i= 0;i<Y;++i)
    //     for (j= 0;j<Z;++j)
    //         B[i][j] = i * Z + j;

    nonThreadedMatMult();
    threadedMatMultPerElement();
    threadedMatMultPerRow();

    return 0;
}
```
