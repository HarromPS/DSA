#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

// TIME COMPLEXITY
// Q1. Find the time complexity of the function in the program below

void function (int arr[],int length)  // one method to pass array in a function
{
    int sum =0;
    int product=1;

    for(int i=0;i<length;i++)
    {
        sum+=arr[i];
        product*=arr[i];
    }
    cout<<"The sum is: "<<sum<<endl;
    cout<<"The product is: "<<product<<endl;

}
int main(){
    int arr[]={2,7,3};
    function(arr,3);
    return 0;
}