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
void showMatrix(float mat[NUMROW][NUMCOL])
{
    int i, j;
    for( i=0; i<NUMROW; i++ ){
        for( j=0; j<NUMCOL; j++ )
            printf("%3.0f ", mat[i][j]);
        printf("\n");
    }
}

void showTranspose( float mat[NUMCOL][NUMROW] ){
    int i, j;
    for( i=0; i<NUMCOL; i++ ){
        for( j=0; j<NUMROW; j++ )
            printf("%3.0f ", mat[i][j]);
        printf("\n");
    }
}

void transpose( float mat[NUMROW][NUMCOL], float transposeMat[NUMCOL][NUMROW] ){
    int i,j;
    for(i = 0; i < NUMROW;i++)
        for(j = 0; j < NUMCOL;j++)
            transposeMat[j][i] = mat[i][j];
}


void main()
{
    float A[NUMROW][NUMCOL] = { {1, 2, 0, 1},{0, 2, 1, 2},{1, 0, 1, 1}};
    float tA[NUMCOL][NUMROW] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    printf("Matrix A: \n");
    showMatrix( A );
    transpose(A,tA);
    printf("\nTranspose Matrix A: \n");
    showTranspose(tA);
}
//Output
//Matrix A:
//1   2   0   1
//0   2   1   2
//1   0   1   1
//
//Transpose Matrix A:
//1   0   1
//2   2   0
//0   1   1
//1   2   1

//Q.3
#include <stdio.h>

void positionMaxMin(double num[],int size, int* posMax, int* postMin){
    int i;
    double max = num[0],min = num[0]; //initialize value
    *posMax = 0;
    *postMin = 0;
    for(i = 1; i < size; i++) {
        if (num[i] > max) {
            *posMax = i;
            max = num[i];
        } else if (num[i] < min) {
            *postMin = i;
            min = num[i];
        }
    }
}

int main(){
    int posMax,posMin;
    double num[] = {2.5,-2.0,1.3,5.7,-1.0,0.0};
    int size = sizeof(num)/sizeof(num[0]);
    positionMaxMin(num,size,&posMax,&posMin);
    printf("posMax = %d\nposMin = %d\n",posMax,posMin);
    return 0;
}

//Q.4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int alpha_arr[5] = { 0,0,0,0,0}; //{a,e,i,o,u}
    char x;
    while (1) {
        x = getchar();
        if (x == EOF) 
            break;
        if (x != '\n') {
            x = tolower(x);
            if (x == 'a')
                alpha_arr[0]++;
            else if (x == 'e')
                alpha_arr[1]++;
            else if (x == 'i')
                alpha_arr[2]++;
            else if (x == 'o')
                alpha_arr[3]++;
            else if (x == 'u')
                alpha_arr[4]++;
        }
    }
    printf("a: %d\n", alpha_arr[0]);
    printf("e: %d\n", alpha_arr[1]);
    printf("i: %d\n", alpha_arr[2]);
    printf("o: %d\n", alpha_arr[3]);
    printf("u: %d\n", alpha_arr[4]);
    return 0;
}

//Q.4 ver.arr

//Q.5

#include <stdio.h>
#include <math.h>

int main(){
    int usin[20],sum = 0;
    double avg1,sd1,avg2,sd2,dob_length = 20.0;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&usin[0],&usin[1],&usin[2],&usin[3],&usin[4],&usin[5],&usin[6],&usin[7],&usin[8],&usin[9],&usin[10],&usin[11],&usin[12],&usin[13],&usin[14],&usin[15],&usin[16],&usin[17],&usin[18],&usin[19]);
    for(int loop = 0; loop < 20; loop++){
        sum += usin[loop];
    }
    avg1 = sum/dob_length;
    printf("AVG = %.4lf\n",avg1);
    sum = 0;
    for(int loop = 0; loop < 20; loop++){
        sum += pow((usin[loop] - avg1),2);
    }
    sd1 = sqrt(sum/dob_length);
    printf("SD = %.4lf\n",sd1);
    sum = 0;
    printf("After removing the outlines:\n");
    for(int loop = 0; loop < 20; loop++){
        if (abs((usin[loop] - avg1)) > (4*sd1))
            dob_length -= 1;
        else
            sum += usin[loop];
    }
    avg2 = sum/dob_length;
    printf("AVG = %.4lf\n",avg2);
    sum = 0;
    for(int loop = 0; loop < 20; loop++){
        if (abs((usin[loop] - avg1)) <= (4*sd1))
            sum += pow((usin[loop] - avg2),2);
    }
    sd2 = sqrt(sum/dob_length);
    printf("SD = %.4lf\n",sd2);
    return 0;
}
