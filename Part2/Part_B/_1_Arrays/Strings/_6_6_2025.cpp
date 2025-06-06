#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

std::string returnIndents(int n){
    std::string temp="\n";
    for(int i=0;i<n;i++){
        temp+="\t";
    }
    return temp;
}
void solve()
{
    std::string str="A:B,C:{";
    std::string res="X";
    for(int i=0;i<str.size();i++){
        if(str[i]==','){
            std::string temp="\n\t";
            res+=temp;
        }
        else if(str[i]=='{'){
            std::string temp="\n\t{\n\t\tA";
            res+="C:";
            res+=temp;
        }
    }
    std::cout<<res<<std::endl;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif

    // ll test;
    // std::cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
