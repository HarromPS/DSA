#include <iostream>
#include <cstdio>
using namespace std;

// Non-comparison based algorithm
// sort a/c to digits position
// time : O(d* (n+b)) ; n-> no of elements, d-> no of digits, b->base being used

class Solution
{
public:
    void countSort(int *arr, int n, int exp)
    {

        // A function to do counting sort of arr[]
        // according to the digit
        // represented by exp.

        // Output array
        int output[n];
        int i, count[10] = {0};

        // Store count of occurrences
        // in count[]
        for (i = 0; i < n; i++)
        {
            count[(arr[i] / exp) % 10]++;
        }

        // Change count[i] so that count[i]
        // now contains actual position
        // of this digit in output[]
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[],
        // so that arr[] now contains sorted
        // numbers according to current digit
        for (i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }

    void countSort2(int *arr,int n,int base){
        int count[10] = {0};
        // store all the occurances to count
        for(int i=0;i<n;i++){
            count[(arr[i]/base) % 10]+=1;
        }
        int output[n];
        // change the count so that it contains the actual positions in output
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }

        // fill output array
        for(int i=n-1;i>=0;i--){
            output[(count[(arr[i]/base)%10]-1)] = arr[i];
            count[(arr[i]/base)%10]--;
        }

        // fill array with sorted elements
        for(int i=0;i<n;i++){
            arr[i]=output[i];
        }
    }
    void radixSort(int *arr, int n)
    {
        int max_digit = maxDigit(arr, n);
        for (int exp = 1; max_digit / exp > 0; exp *= 10)
        {
            countSort2(arr, n, exp);
        }
    }

    int maxDigit(int *arr, int n)
    {
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[max] < arr[i])
            {
                max = i;
            }
        }

        return arr[max];
        // int len = 0;
        // while (max > 0)
        // {
        //     len += 1;
        //     max /= 10;
        // }
        // return len;
    }
    void printArray(int *arr, int n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 6;
    int *a = (int *)malloc(sizeof(int) * n);
    int temp[] = {40, 20, 60, 10, 50, 30};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    Solution s;
    s.radixSort(a, n);
    s.printArray(a, n);
    return 0;
}