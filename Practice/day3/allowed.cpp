#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<char> set;
    string s = "ab";
    string arr[]= {"a","b","c","ab","cb","abc"};
    int count=0;
    for(int i=0;i<s.size();i++){
        set.insert(s[i]);
    }
    for(int i=0;i<arr->size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(set.find(arr[i][j])==set.end()){
                count++;
                break;
            }
        }

    }
    cout<<arr->size()-count<<endl;
    return 0;
}