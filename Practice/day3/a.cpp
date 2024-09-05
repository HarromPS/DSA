#include <iostream>
#include <cstdio>
using namespace std;

int maximizeSum(int *nums, int numsSize, int k)
{
    // sort
    int ind, temp;
    for (int i = 0; i < numsSize - 1; i++)
    {
        ind = i;
        for (int j = i + 1; j > 0; j--)
        {
            if (nums[j] < nums[ind])
            {
                ind = j;
            }
        }
        temp = nums[ind];
        nums[i] = nums[ind];
        nums[ind] = temp;
    }

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += nums[numsSize - 1];
        nums[numsSize - 1] = nums[numsSize - 1] + 1;
    }
    return ans;
}
int main()
{
    int n=3;
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = 5;
    arr[1] = 5;
    arr[2] = 5;
    int ans = maximizeSum(arr,n, 2);
    // printf("%d", ans);
    return 0;
}