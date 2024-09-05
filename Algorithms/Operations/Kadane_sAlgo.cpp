#include <iostream>
#include <cstdio>
using namespace std;

// Kadane's algorithm -> finding the sub-array with the max sum
int maxSum(int *arr, int size)
{
    int i = 0;
    int sum = 0, initSum = -1;
    while (i < size)
    {
        initSum += arr[i];
        if (sum < initSum)
        {
            sum = initSum;
        }
        if (initSum < 0)
        {
            initSum = 0;
        }
        i++;
    }
    return sum;
}

int maxSum2(int *arr, int size)
{
    int i = 0;
    int sum = 0, initSum = 0;
    while (i < size)
    {
        initSum += arr[i];
        sum = (initSum > sum ? initSum : sum);
        initSum=(initSum<0?0:initSum);
        i++;
    }
    return sum;
}
int main()
{

    // Finding the max sum in the sun array
    int arr[6] = {-5, 4, 6, -3, 4, -1};
    int result = maxSum2(arr, 6);
    cout << result << endl;
    return 0;
}