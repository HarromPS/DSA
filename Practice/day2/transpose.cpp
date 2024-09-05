#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int matrix[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int matrixSize=3;
    int matrixColSize=3;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}