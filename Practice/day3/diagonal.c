#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 5
#define N 5

// start from leftUpper
void leftUpper(int arr[][5],int rowSize)
{
    for(int i=0,j=0;i<rowSize && j<N;i++,j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

// start from rightUpper
void rightUpper(int arr[][N], int rowSize)
{
    for(int i=0,j=N-1;i<rowSize && j>=0;i++,j--){
           printf("%d ",arr[i][j]);
    }
    printf("\n");
}
// start from leftBottom
void leftBottom(int arr[][N], int rowSize)
{
    for(int i=rowSize-1,j=0;i>=0 && j<N;i--,j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
// start from rightBottom
void rightBottom(int arr[][N], int rowSize)
{
    for(int i=rowSize-1,j=N-1;i>=0 && j>=0;i--,j--){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
void p()
{
}

int main()
{
    int row = 5, col = 5;
    int arr[][5] = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25},};

    leftUpper(arr,row);
    rightUpper(arr,row);
    leftBottom(arr,row);
    rightBottom(arr,row);
    return 0;
}
