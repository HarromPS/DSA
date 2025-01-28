#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
#include<algorithm>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Bit Manipulation

1. Decimal to binary
2. Binary to Decimal 
3. 1s complement
4. 2s complement

*/

class Solution{
public: 
    int powerExponentiation(int n,int x){
        // pow(n,x)
        if(n==0 || x==0) return 1;
        if(x==1) return n;

        int ans=1;
        while(x>0){
            if(x%2==0){
                // if even 
                n=n*n;
                x=x/2;
            }else{
                ans=ans*n;
                x-=1;
            }
        }
        return ans;
    }

    // 1. Decimal to binary
    // TC:O(log n)
    std::string decimalToBinary(int n){
        if(n==0) return "0";
        std::string bin="";
        while(n>=1){
            int rem=n%2;
            bin+=rem==1?'1':'0';
            n=n/2;
        }
        std::reverse(bin.begin(),bin.end());
        return bin;
    }

    // 2. Binary to Decimal 
    // TC:O(log n base 2 * m)
    int binaryToDecimal(std::string bin){
        int m=bin.size();
        int res=0;
        for(int i=0;i<m;i++){
            int num=bin[i]-'0';
            res+=(powerExponentiation(2,m-i-1) * num);
        }
        return res;
    }

    int binaryToDecimal2(std::string bin){
        int m=bin.size();
        int res=0;
        int pair=1;
        for(int i=m-1;i>=0;i--){
            if(bin[i]=='1'){
                res+=pair;
            }
            pair*=2;
        }
        return res;
    }

    // 3. 1s complement 
    std::string _1sComplement(int m){
        std::string bin = decimalToBinary(m);
        // flip all bits 
        std::string _1sComp="";
        
        int n=bin.size();
        for(int i=0;i<n;i++){
            if(bin[i]=='1') _1sComp+='0';
            else _1sComp+='1';
        }
        return _1sComp;
    }

    // 4. 2s complement 
    std::string _2sComplement(int m){
        std::string _1sComp = _1sComplement(m);
        std::string _2sComp="";
        
        int n=_1sComp.size();
        int carry=1;            // to add 
        for(int i=n-1;i>=0;i--){
            if(_1sComp[i]=='0' && carry==1){
                _2sComp+='1';
                carry=0;
            }
            else if(_1sComp[i]=='0' && carry==0){
                _2sComp+='0';
            }
            else if(_1sComp[i]=='1' && carry==0){
                _2sComp+='1';
            }
            else if(_1sComp[i]=='1' && carry==1){
                _2sComp+='0';
                carry=1;
            }
        }
        if(carry==1){
            _2sComp+='1';
        }
        std::reverse(_2sComp.begin(),_2sComp.end());
        return _2sComp;
    }
    
};

void solve(){
    int n;
    std::cin>>n;
    Solution s;

    
    // 1. Decimal to binary
    std::string bin=s.decimalToBinary(n);
    std::cout<<bin<<" ";
    
    // 2. Binary to Decimal
    int res=s.binaryToDecimal2(bin);
    std::cout<<res<<std::endl;

    // 3. 1s complement
    bin=s._1sComplement(n);
    std::cout<<bin<<std::endl;

    // 4. 2s complement
    bin=s._2sComplement(n);
    std::cout<<bin<<std::endl;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // while(t--) solve2();
    return 0;
}