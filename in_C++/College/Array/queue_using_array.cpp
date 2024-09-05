#include <iostream>
#include <cstdio>
using namespace std;

// Array queue using using function, pointer, recursion
int Queue(int arr[], int n)
{
    int p, i = 0;
    cout << "Enter the new element: ";
    cin >> p;
    if (p == 0)
    {
        cout<<"End"<<endl;
    }
    else
    {
        cout << "Type '0' to end" << endl;
        for (i = 0; i < n; i++)
        {
            arr[i] = arr[i + 1];
            if (i == (n - 1))
            {
                arr[i] = p;
            }
        }
        cout << "New queue is: (";
        for (int i = 0; i < n; i++)
        {
            if (i <= (n - 2))
            {
                cout << arr[i] << ", ";
            }
            else
            {
                cout << arr[i];
            }
        }
        cout << ")" << endl;

        return Queue(arr, n);
    }
}
int main()
{
    int n;
    cout << "Type the size of your array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    cout << "Queue elements in the array are: (";
    for (int i = 0; i < n; i++)
    {
        if (i <= (n - 2))
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << ")" << endl;
    Queue(arr, n);

    return 0;
}