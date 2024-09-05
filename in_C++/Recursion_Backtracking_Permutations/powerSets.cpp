#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void power(vector<int>& nums,vector<int>& curr,int i){
        if(i>=nums.size()){
            this->ans.push_back(curr);
            for(int i=0;i<curr.size();i++){
                cout<<curr[i]<<" ";
            }
            cout<<endl;
            return;
        }

        curr.push_back(nums[i]);
        power(nums,curr,i+1);
        curr.pop_back();
        power(nums,curr,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        power(nums,curr,0);
        return this->ans;
    }
};
int main(){
    vector<int> n = {1,2,3};
    Solution s;
    s.subsets(n);
    return 0;
}