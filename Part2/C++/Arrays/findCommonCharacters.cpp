#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    // vector<string> commonChars(vector<string>& words) {
    //     vector<unordered_map<char,int>> v(words.size());
    //     for(int i=0;i<words.size();i++){
    //         unordered_map<char,int> mp;
    //         for(int j=0;j<words[i].size();j++){
    //             if(mp.find(words[i][j])!=mp.end()){
    //                 mp[words[i][j]]+=1;
    //             }else{
    //                 mp[(char)words[i][j]]=1;
    //             }
    //         }
    //         v[i]=mp;
    //         mp.clear();
    //     }
        
    //     for(int i=1;i<words.size();i++){
    //         for (auto& pair : v[i-1]) {
    //             if(v[i].find(pair.first)!=v[i].end()){
    //                 pair.second = min(pair.second, v[i].find(pair.first)->second);
    //             }else{
    //                 pair.second = 0;
    //             }
    //         }     
    //         v[i].clear();
    //         v[i] = v[i-1];
    //     }
    //     vector<string> ans;
    //     for(auto it:v[v.size()-1]){
    //         int n=it.second;
    //         while(n>0){
    //             ans.push_back(string(1,it.first));
    //         }
    //     }
    //     return ans;
    // }

    // Memory efficient
    vector<string> commonChars(vector<string>& words) {
       vector<int> freq(26,words.size());

        for(int i=0;i<words.size();i++){
            vector<int> currfreq(26,0);
            for(auto it:words[i]){
                currfreq[it-'a']++;
            }

            for(char c='a';c<='z';c++){
                freq[c-'a'] = min(freq[c-'a'], currfreq[c-'a']);
            }
        }
        vector<string> ans;
        for(char c='a';c<='z';c++){
            while(freq[c-'a']--){
                ans.push_back(string(1,c));
            }
        }
        return ans;
    }
};

// Implementation of 
int main(){
    vector<string> arr = {"bella","label","roller"};
    vector<string> ans = Solution().commonChars(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}