#include<iostream>
#include<cstdio>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#include<unordered_set>
// In C++, there is a library called unorderd set for hashing
int main(){

    // Creating a hash object of type Integer
    unordered_set<int> s;
    unordered_map<int,int> p;

    // insertion
    s.insert(10);
    s.insert(10);
    s.insert(10);
    s.insert(65);
    s.insert(32);
    s.insert(123);
    s.insert(432);

    // finding out a result from the set
    // cout<<s.find(10)<<endl;
    if(s.find(10)!=s.end()){
        cout<<"Found"<<endl;
    }
    else {
        cout<<"Not Found"<<endl;
    }

    // iterate the set
    for(auto iter = s.begin();iter!=s.end();iter++){
        cout<<*iter<<" ";
    }

    // size of the set
    cout<<"\nsize: "<<s.size()<<", max-size: "<<s.max_size()<<endl;

    // repetation of a element in the set, then its count
    cout<<s.count(10)<<endl;    // Number of elements with specified key. This function only makes sense for unordered_multisets; for unordered_set the result will either be 0 (not present) or 1 (present).

    return 0;
}