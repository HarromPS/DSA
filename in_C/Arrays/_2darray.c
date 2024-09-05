#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int RowMin(int *prow, int c);

int main()
{
    int a[MAX][MAX];
    int r, c, min;
    int i = 0, j = 0;

    printf("Enter number of rows & columns of array:\n");
         scanf("%d %d", &r, &c);

    printf("\nEnter elements of 2-D array:\n");
         for(i=0; i<r; i++)
         {
                  for(j=0; j<c; j++)
                  {
                           scanf("%d", &a[i][j]);
                  }
         }
    for(i=0;i<r;i++)
    {
        min = RowMin(a[i], c);
        printf("The min in row %d is %d\n",i, min);
    }
    return 0;
}

int RowMin(int *prow, int ncols)
{
    int temp, i;
    int a[*prow][ncols]; //this is where it is messing up
    /*  int*, you use a[*pow][0] out of bounds, you use a[*pow][0] without initializing it  */
    temp = a[*prow][0];
    for(i=0; i<ncols; i++)
    {
        printf("Good5 ");
        if(temp > a[*prow][i])
        {
            temp = a[*prow][i];

        }
    }
    return temp;
}