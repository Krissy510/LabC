//Q1.
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
    printf("\n\nAftersorting:\n", size);
    displayArray( val, size );
}
//Output
//The array of 6 floating-point elements:
//6.21  4.83  9.49 10.66  1.02  7.77
//
//
//Aftersorting:
//1.02  4.83  6.21  7.77  9.49 10.66

//Q2
