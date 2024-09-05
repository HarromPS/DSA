#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    string v[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s="2";
    vector<string> ans;
    if(s.size()<=1){
        for(int i=0;i<s.size();i++){
            for(int j=0;j<v[(int)s[i]-48].size();j++){
                string str = v[(int)s[i]-48];
                // ans.push_back((string)str.at(j)); not works gives error
                ans.push_back((string)str.substr(j,1));
                cout<<str.at(j)<<" ";
                str="";
            }
            // cout<<ans[i]<<" ";
        }
        for (int i = 0; i < s.size(); i++) {
            int digit = (int)s[i] - '0';
            for (int j = 0; j < v[digit].size(); j++) {
                string str = v[digit];
                ans.push_back((string)str.substr(j, 1));
                cout << str[j] << " ";
                str = "";
            }
            // cout << ans[i] << " ";
        }
    }
    else {
        cout<<"False";
    }
    // vector<int> n;
    // n.push_back(-1);
    // n.push_back(-1);
    // int i=0;
    // while(s[i]!='\0'){
    //     n.push_back((int)(s[i]-48));
    //     i++;
    // }

    // for(int i=3;i<n.size();i++){
    //     for(int j=i;j<n[i];j++){
    //         for(int k=j+1;k<v[j].size();k++){

    //         }
    //     }
    // }
    return 0;

}