#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// Using recursion to solve letter combination problem
/*
e.g
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

// // function passed increment/decrement operator
// void function(int i){
//     if(i>=5){
//         return ;
//     }
//     cout<<i<<" ";
//     // return function(i++);   // only 1 is passed & incremented after passing so, 1 is passed
//     return function(++i);   // only 1 is passed & incremented after passing so, 1 is passed
// }

class Solution
{
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void letterComb(string digits, string curr, int ind)
    {
        if (ind == digits.size())
        {
            cout << curr << endl;
            return;
        }

        int n = (int)digits[ind] - '0';
        for (int i = 0; i < v[n].size(); i++)
        {
            letterComb(digits, curr + v[n][i], ind + 1);
        }
    }
};
int main()
{
    string digits = "23";
    Solution s;
    s.letterComb(digits, "", 0);

    vector<string> ans;
    return 0;
}