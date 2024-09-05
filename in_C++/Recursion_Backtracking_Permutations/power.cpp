#include<iostream>
#include<cstdio>
using namespace std;

// Power of a string is the collection of all the subsets of a set
// "abc" => {abc, ab, bc, ac, a, b, c, " "} => 8
/*
                abc
            a         " "
        ab    a      b    " "
    abc   ab ac a   bc c  c  " "
*/

void powerSet(string s,string ans,int i){
    if(s[i]=='\0'){
        cout<<(ans+" ");
        return;
    }
    powerSet(s,ans+s[i],i+1);
    powerSet(s,ans,i+1);

}
int main(){
    string ans="";
    powerSet("abc",ans,0);
    return 0;
}