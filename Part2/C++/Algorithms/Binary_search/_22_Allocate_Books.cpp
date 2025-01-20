#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Allocate Minimum Pages

You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
*/

class Solution{
public: 
    bool helper(std::vector<int> &arr, int maxPageAllowed, int students){
        // check for each book 
        int i=0;
        int n=arr.size();
        int maxPagesAllocated=0;   // max pages allocated to a student
        int studentGotBooks=1;     // number of students got books, at least 1 student get all books
        while(i<n){
            // if student can hold pages then allocate the book
            if(maxPagesAllocated + arr[i] <= maxPageAllowed){
                maxPagesAllocated += arr[i];
            }else{
                maxPagesAllocated=arr[i];    // allocate this book to other student
                studentGotBooks+=1;
            }
            i++;
        }
        if(studentGotBooks > students){ 
            // no of students having books exceeded limit and cant fit it into other students
            return false;
        }
        return true;    
    }

    int findPagesBrute(std::vector<int> &arr, int k) {
        int n=arr.size();

        // base condition
        if(k > n) return -1;    // not possible to allocate books to k students

        int maxPagesAllowed=*max_element(arr.begin(),arr.end());
        int totalPages=std::accumulate(arr.begin(),arr.end(),0);
        for(int i=maxPagesAllowed;i<=totalPages;i++){
            // check all books allocation to m students
            bool res=helper(arr,i,k);
            if(res==true){
                return i;   // min pages allocated to a student to be maximum
            }
        }
        return -1;   // not possible to allot books to k students
    }

    int findPages(std::vector<int> &arr, int k) {
        int n=arr.size();

        // base condition
        if(k > n) return -1;    // not possible to allocate books to k students

        int ans=-1;
        int low=*max_element(arr.begin(),arr.end());
        int high=std::accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            // check all books allocation to m students
            bool res=helper(arr,mid,k);
            if(res==true){
                ans=mid;   // min pages allocated to a student to be maximum
                high=mid-1; // minimize ans
            }else{
                low=mid+1;
            }
        }
        return low;   // not possible to allot books to k students
    }
};

void solve(){
    int n;  
    int k;
    std::cin>>n;
    std::cin>>k;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    // int res=s.findPagesBrute(arr,k);
    // std::cout<<res<<std::endl;
    int res=s.findPages(arr,k);
    std::cout<<res<<std::endl;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // while(t--) solve2();
    return 0;
}