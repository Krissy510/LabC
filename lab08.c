//Q1.1
#include<stdio.h>
void swap( float* val1Addr, float* val2Addr )
{
    float temp;
    temp = *val1Addr;
    *val1Addr = *val2Addr;
    *val2Addr = temp;
}
void bubbleSort( float num[], int size )
{
    int i, j;
    for( i=0; i<size-1; i++)
        for( j=1; j<size; j++ )
            if( num[j] < num[j-1] )
                swap( &(num[j]), &(num[j-1]) );
}
void displayArray( float num[], int size )
{
    int i;
    for( i=0; i<size; i++)
        printf("%5.2f ", num[i]);
    printf("\n");
}
void main()
{
    float val[] = {6.21, 4.83, 9.49, 10.66, 1.02, 7.77};
    int size = sizeof(val)/sizeof(float);
    //determine the size
    printf("The array of %d floating-point elements:\n", size);
    displayArray( val, size );
    bubbleSort( val, size );
    printf("\n\nAfter sorting:\n", size);
    displayArray( val, size );
}
//Output
//The array of 6 floating-point elements:
//6.21  4.83  9.49 10.66  1.02  7.77
//
//
//After sorting:
//1.02  4.83  6.21  7.77  9.49 10.66

//Q1.2
#include<stdio.h>
void swap( float* val1Addr, float* val2Addr )
{
    float temp;
    temp = *val1Addr;
    *val1Addr = *val2Addr;
    *val2Addr = temp;
}
void bubbleSort( float num[], int size )
{
    int i, j;
    for( i=0; i<size-1; i++)
        for( j=1; j<size; j++ )
            if( num[j] > num[j-1] )
                swap( &(num[j]), &(num[j-1]) );
}
void displayArray( float num[], int size )
{
    int i;
    for( i=0; i<size; i++)
        printf("%5.2f ", num[i]);
    printf("\n");
}
void main()
{
    float val[] = {6.21, 4.83, 9.49, 10.66, 1.02, 7.77};
    int size = sizeof(val)/sizeof(float);
    //determine the size
    printf("The array of %d floating-point elements:\n", size);
    displayArray( val, size );
    bubbleSort( val, size );
    printf("\n\nAfter sorting:\n", size);
    displayArray( val, size );
}
//Output
//The array of 6 floating-point elements:
//6.21  4.83  9.49 10.66  1.02  7.77
//
//
//After sorting:
//10.66  9.49  7.77  6.21  4.83  1.02

//Q2.1
#include<stdio.h>
#define NUMROW 3
#define NUMCOL 4
void addMatrices( float in1[NUMROW][NUMCOL],float in2[NUMROW][NUMCOL],float out[NUMROW][NUMCOL])
{
    int i, j;
    for( i=0; i<NUMROW; i++ )
        for( j=0; j<NUMCOL; j++ )
            out[i][j] = in1[i][j] + in2[i][j];
}
void showMatrix(float mat[NUMROW][NUMCOL])
{
    int i, j;
    for( i=0; i<NUMROW; i++ ){
        for( j=0; j<NUMCOL; j++ )
            printf("%3.0f ", mat[i][j]);
        printf("\n");
    }
}
void main()
{
    float A[NUMROW][NUMCOL] = { {1, 2, 0, 1},{0, 2, 1, 2},{1, 0, 1, 1}  };
    float B[NUMROW][NUMCOL] = { {2, 3, 1, 2},{0, 1, 0, 0},{2, 1, 0, 0}  };
    float C[NUMROW][NUMCOL];
    printf("Matrix A: \n");
    showMatrix( A );
    printf("\nMatrix B: \n");
    showMatrix( B );
    addMatrices( A, B, C );
    printf("\nMatrix C = A + B: \n");
    showMatrix( C );
}
//Output
//Matrix A:
//  1   2   0   1
//  0   2   1   2
//  1   0   1   1
//
//Matrix B:
//  2   3   1   2
//  0   1   0   0
//  2   1   0   0
//
//Matrix C = A + B:
//  3   5   1   3
//  0   3   1   2
//  3   1   1   1

//Q2.2
