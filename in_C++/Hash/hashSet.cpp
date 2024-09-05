#include <iostream>
#include <cstdio>
using namespace std;

// Library
#include <unordered_set>

int main()
{
    // Instantiate the object of unordered set
    unordered_set<int> s={1,2,3,4,4,5,6,7};
    // s.insert(12);
    // int i=*(s.begin());
    // cout<<i<<" ";//<<s.end()<<endl;

    unordered_set<int> :: iterator iter;
    // iter=s;
    // for(iter;iter!=s.end();iter++){
    //     cout<<*iter<<" ";
    // }
    if (s.find(12) != s.end())
    {
        cout << "found" << endl;
    }
    cout<<s.size()<<" "<<(s.max_size())<<endl;
    int n=0;
    // cout<<type_info(n)<<endl;
    return 0;
}