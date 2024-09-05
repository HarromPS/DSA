#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class KthLargest
{
public:
    int k;
    vector<int> ans;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        this->ans = nums;
        sort(this->ans.begin(), this->ans.end());
        for (int i = 0; i < this->ans.size(); i++)
        {
            cout << this->ans[i] << " ";
        }
    }

    int add(int val)
    {
        // insert manually
        int low = 0, high = this->ans.size() - 1;
        int mid = (low + high) / 2;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (this->ans[mid] == val)
            {
                this->ans.insert(ans.begin() + this->ans[mid], val);
                low = 2;
                high = 1;
                break;
            }
            else if (this->ans[mid] < val)
            {
                if (high - low <= 3 && high - low >= 0)
                {
                    for (int i = low; i <= high; i++)
                    {
                        if (this->ans[i] >= val)
                        {
                            this->ans.insert(this->ans.begin() + i, val);
                            low = 2;
                            high = 1;
                            break;
                        }
                    }
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (this->ans[mid] > val)
            {
                if (high - low <= 3 && high - low >= 0)
                {
                    for (int i = low; i <= high; i++)
                    {
                        if (this->ans[i] >= val)
                        {
                            this->ans.insert(this->ans.begin() + i, val);
                            low = 2;
                            high = 1;
                            break;
                        }
                    }
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return this->ans[this->ans.size() - this->k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(2);
    v.push_back(5);
    KthLargest *obj = new KthLargest(3, v);
    int a[] = {3, 5, 10, 9, 4};
    for (int i = 0; i < 5; i++)
    {
        cout << obj->add(a[i]) << " ";
    }
    return 0;
}