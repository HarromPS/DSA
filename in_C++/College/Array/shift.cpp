#include <iostream>
#include <cstdio>
using namespace std;

// Q2. Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements

int Rotate(int arr[], int n, int r)
{
    int temp;
    for(int i=0;i<r;i++)
    {
        temp=arr[0];
        for(int j=0;j<n-1;++j)
        {
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
}
int main()
{
    int n;
    cout << "Enter a size of array: ";
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "\nThe array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    cout << "\nEnter the number of rotations: ";
    int rotate;
    cin>>rotate;
    Rotate(array,n,rotate);
    cout << "\nThe Rotated array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }

    return 0;
}