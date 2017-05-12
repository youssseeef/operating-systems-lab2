# Operating Systems - Lab 2 Report
1. Part 1: Matrix Multithreaded Multiplication  
* We had to make some sample Matrix instead of the one provided in main just for testing purposes
```
int A[X][Y] = {{1, 2, 3}, {4, 5, 6}};
int B[Y][Z] = {{7, 8}, {9, 10}, {11, 12}};
int C[X][Z];
```
* Implementing a single-threaded matrix multiplication was fairly easy, we implemented both 
the dot product and the single threaded function provided

* We have used the following structure
```
struct thread_data
{
    // You may need this fill this struct to pass and receive data from
    // threads
    //output row;
    int row;
    //output column;
    int column;
    //value of element
    int value;

    // computed row
    int ret_row[X];
};

```