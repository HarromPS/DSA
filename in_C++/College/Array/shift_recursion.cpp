// // #include <iostream>
// #include <cstdio>
// using namespace std;

// // Q3. Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements using recursion
// static int k = 0;
// int Rotate(int arr[], int n, int r)
// {
//     int temp;
//     if (k < r)
//     {
//         temp = arr[0];
//         for (int j = 0; j < n - 1; ++j)
//         {
//             arr[j] = arr[j + 1];
//         }
//         arr[n - 1] = temp;
//     }
//     else
//     {
//         k++;
//         return Rotate(arr, n, r);
//     }
// }
// int main()
// {
//     int n;
//     cout << "Enter a size of array: ";
//     cin >> n;
//     int array[n];
//     cout << "Enter the elements of the array\n";
//     for (int i = 0; i < n; ++i)
//     {
//         cout << i + 1 << ": ";
//         cin >> array[i];
//     }
//     cout << "\nThe array is:\n";
//     for (int i = 0; i < n; ++i)
//     {
//         cout << array[i] << " ";
//     }
//     cout << "\nEnter the number of rotations: ";
//     int rotate;
//     cin >> rotate;
//     Rotate(array, n, rotate);
//     cout << "\nThe Rotated array is:\n";
//     for (int i = 0; i < n; ++i)
//     {
//         cout << array[i] << " ";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;


void Filter(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            count++;
    for (int i = 0; i < count; i++)
        arr[i] = 0;
    for (int i = count; i < n; i++)
        arr[i] = 1;
}
void print(int arr[], int n)
{
    cout << "Array after Filter is "<<endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"The array is: "<<endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    Filter(arr, n);
    print(arr, n);
    return 0;
}

