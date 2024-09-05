#include<iostream>
#include<cstdio>
using namespace std;

class Solution
{
    public: 
        int** spiralMatrix(int n)
        {
            int** arr=(int**)malloc(sizeof(int*)*n);
            **arr={
                {1,2,3},
                {8,9,4},
                {7,6,5}
            };
            return arr;
        }
};
int main(){
    // GOOGLE
    /* Q. Given a positive integer n, generate a square matrix 
    filled with elements from 1 to n^2 in spiral order.

    input : 3
    output: 
    [
        [1,2,3]
        [8,9,4]
        [7,6,5]
    ]
    */

   int n;
   cout<<"Enter a val: ";
   cin>>n;

    return 0; 
}