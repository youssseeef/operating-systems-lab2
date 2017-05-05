#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
/* number of matrix columns and rows */
#define X 2
#define Y 3
#define Z 2

int A[X][Y] = {{1, 2, 3}, {4, 5, 6}};
int B[Y][Z] = {{7, 8}, {9, 10}, {11, 12}};
int C[X][Z];

/*** functions for non threaded multiplications ****/
int dotProduct(int r, int c)
// r and c are the row and coloumn of matrices A and B, respectively
{
    //printf("dotProduct function is not implemented!\n");
    // Calculate the dot product of the row r from A with the column c from B

    int i, sum = 0;
    // loop over the rows of A and the columns of B
    for (i = 0; i < Y; i++) {
			//printf("%d \n", B[0][0] );
			sum += (A[r][i] * B[i][c]);
    }
    return sum;
}
void nonThreadedMatMult()
{
    //printf("nonThreadedMatMult function is not implemented yet\n");
		int i, j = 0;
    printf("Non-threaded C elements: \n");
		for (i = 0; i < X; i++) {
			for (j = 0; j < Z; j++) {
				C[i][j] = dotProduct(i, j);
				printf("%d\n", C[i][j]);
			}
		}
    printf("End of Non-threaded C elements \n");
    printf("\n");
    printf("\n");
    printf("\n");
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

    // computed row
    int ret_row[X];
};

struct thread_data thread_data_array[X * Z];
struct thread_data thread_data_row_array[X];

void *dotProductThreadElem(void *threadArgs)
// Element by element threaded calculation
{
    // Exctract the passed arguments from the threadArgs structure
     int r = thread_data_array[(int)(uintptr_t)threadArgs].row;
     int c = thread_data_array[(int)(uintptr_t)threadArgs].column;

    // Calculate the dotProduct
    int i;
    for (i = 0; i < Y; i++) {
      thread_data_array[(int)(uintptr_t)threadArgs].value += ((A[r] [i]) * (B[i] [c]));
    }

    // printf("%d \n", thread_data_array[(int)threadArgs]);

    // Exit the thread
    pthread_exit(NULL);
}


void *dotProductThreadRow(void *threadArgs)
// Element by element threaded calculation
{
    // Exctract the passed arguments from the threadArgs structure
    // get the desired row
     int r = thread_data_row_array[(int)(uintptr_t)threadArgs].row;
     printf("row thread number = %d\n", r);



    // Exit the thread
    pthread_exit(NULL);
}

void fillTheArrayOfStructsWithData()
{
    int i, j, a, b;
    a = 0;
    b = 0;

    for (i = 0; i < X; i++)
    {
		for (j = 0; j < Z; j++) {
      thread_data_array[a].row = i;
      thread_data_array[a].column = j;
      a++;
		}
    thread_data_row_array[b].row = i;
    ++b;
    }
}


void fillTheArrayOfArrStructsWithData() {
  int i, b;
  b = 0;

  for (i = 0; i < X; i++)
  {
    thread_data_row_array[b].row = i;
    ++b;
  }
}

void threadedMatMultPerElement()
{
    fillTheArrayOfStructsWithData();
    pthread_attr_t attr;
    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		pthread_t threads[X*Z];

		// create the thread workers
    int i;
    for(i = 0; i < X * Z ; i++){
			int error = pthread_create(&threads[i], &attr, dotProductThreadElem, (void *)(uintptr_t)i);
       if (error) {
          printf("ERROR; return code from pthread_create() is %d\n", error);
          exit(-1);
        }
    }

    // Join the X*Z threads
		for(i = 0; i < X * Z ; i++){
			(void) pthread_join(threads[i], NULL);
		}

    // Print the elements of C
    printf("thread data array values for per element threading: \n");
    int j;
    for (j = 0; j < X*Z; j++) {
      printf("%d\n",thread_data_array[j].value);
    }
    printf("end of per element threading: \n");
    printf("\n");
    printf("\n");
    printf("\n");
}

/*** functions for threaded row multiplications ****/
// Similar to the element multiplication but only X threads are created

void threadedMatMultPerRow()
{
      fillTheArrayOfArrStructsWithData();
      printf("threadedMatMultPerRow function start \n");
      pthread_attr_t arr_attr;
      /* Initialize and set thread detached attribute */
      pthread_attr_init(&arr_attr);
      pthread_attr_setdetachstate(&arr_attr, PTHREAD_CREATE_JOINABLE);
      // printf("threadedMatMultPerElement function\n");

  		pthread_t arr_threads[X];

  		// create the thread workers
      int j;
      for(j = 0; j < X  ; j++){
  			int error = pthread_create(&arr_threads[j], &arr_attr, dotProductThreadRow, (void *)(uintptr_t)j);
         if (error) {
            printf("ERROR; return code from pthread_create() is %d\n", error);
            exit(-1);
          }
      }

      // Join the X threads
  		for(j = 0; j < X  ; j++){
  			(void) pthread_join(arr_threads[j], NULL);
  		}


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

    // nonThreadedMatMult();
    // threadedMatMultPerElement();
    threadedMatMultPerRow();

    return 0;
}
