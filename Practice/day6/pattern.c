#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    
    int k = (2*n)-1;

    // gives error, as initializing variable length arrays in C lang is not allowed
    // int arr[k][k]= {n};

    // but declaration is allowed
    int arr[k][k];

    for(int i=0;i<k; i++){
        for(int j=0;j<k;j++){
            arr[i][j] = n;
            // printf("%d ",arr[i][j]);
        }
        // printf("\n");
    }
    
    int barrierIndexLeft = 1;
    int barrierIndexRight = (2*n)-1;
    // now main pattern logic
    for(int i=1;i<(2*n);i++){
        int val = n-1;
        if(i <= ((2*n)-1)/2){
            for(int j=1;j<((2*n));j++){
                if(j<barrierIndexLeft || j>barrierIndexRight-1){
                    arr[i][j] = val+1;
                }
                else{
                    arr[i][j] = val;
                }
            }
        }
        barrierIndexLeft +=1;
        barrierIndexRight -=1;
    }

     for(int i=0;i<k; i++){
        for(int j=0;j<k;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}