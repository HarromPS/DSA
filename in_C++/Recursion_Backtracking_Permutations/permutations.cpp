#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    void permute(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            this->ans.push_back(nums);
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
            return;
        }

        for (int i = l; i <= r; i++)
        {
            swap(nums, l, i);
            permute(nums, l + 1, r); // backtracked
            swap(nums, l, i);
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        permute(nums, 0, nums.size() - 1);
        return this->ans;
    }
};

int main()
{
    vector<int> nums;
    nums = {1, 2, 3};
    Solution s;
    s.subsets(nums);
    return 0;
}