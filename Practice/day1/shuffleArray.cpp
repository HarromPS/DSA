#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> arr=nums;
        int j = n+1, i = 0;
        nums.clear();
        while (i < n && j<2*n)
        {
            if (i % 2 == 0)
            {
                nums.push_back(arr[i]);
                i++;
            }
            else
            {
                nums.push_back(arr[j]);
                j++;
            }
        }
        return nums;
    }
};
int main()
{
    class Solution S;
    vector<int> v1={2,5,1,3,4,7};
    for(int i=0;i<6;i++){
        cout<<v1[i]<<" ";
    }
    vector<int> v2=S.shuffle(v1,3);
    for(int i=0;i<6;i++){
        cout<<v2[i]<<" ";
    }
    

    return 0;
}