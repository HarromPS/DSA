#include <iostream>
#include <cstdio>
using namespace std;

// Finding duplicate elements in the array using pointer and function
int Duplicate(int arr[],int count[],int n)
{
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count[i]++;
            }
        }
    }

}
int main()
{
    int n;
    cout << "Type the size of your array: ";
    cin >> n;
    int arr[n];
    int count[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    cout<<"The elements of the array are: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " element: " << arr[i] << endl;
    }
    Duplicate(arr,count,n);
    for (int i = 0; i < n; i++)
    {
        if (count[i] > 1)
        {
            printf("\n%d is a duplicate element in the array\n", arr[i]);
            printf("%d occured: %d times\n", arr[i], count[i]);
        }
    }
    return 0;
}