#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*
You are playing an array game in which you are given two arrays arr and brr, each of size n.
Each array is a permutation of n positive integers.

In one operation, you can perform either of the following two steps:

Rotate the array arr anti-clockwise.
Remove the first element of both the arrays if they are the same.

Find the minimum number of operations required to make both the arrays empty.

n = 3
arr[] = {1, 2, 3}
brr[] = {2, 1, 3}

Ans: 5

Explanation:
operation 1: Rotate arr anti-clockwise.
It becomes {2, 3, 1}.
operation 2: Remove first element {2} from
both the arrays. arr = {3, 1} and brr = {1, 3}.
operation 3: Rotate arr anti-clockwise. arr = {1, 3}.
operation 4: Remove {1} from both the arrays.
operation 5: Remove {3} from both the arrays.
*/

void rotate(int *arr, int n, int index)
{
    int temp = arr[index];
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}
int main()
{
    int arr[] = {1, 2, 3};
    int brr[] = {2, 1, 3};
    int size = sizeof(brr) / sizeof(int);

    vector<int> v;
    v.push_back(1);
    cout<<v.size()<<endl;
    v.erase(v.begin(),v.begin()+1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    // for (int i = 0; i < size; i++)
    // {
    //     // rotate(arr, 3, 1);
    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << arr[j] << " ";
    //     }
    //     cout << endl;
    // }
    int count = 0;
    int i = 0, j = 0;


    // for (int j = 0; j < size; j++)
    // {
    //     cout << arr[j] << " ";
    // }
    cout <<count<< endl;
    return 0;
}