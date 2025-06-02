#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths.
Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList

The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0

Input:

wordList = {"des","der","dfr","dgt","dfs"}
startWord = "dfs", targetWord= "dfs",

Output:
3

Explanation:

The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".

*/

// Solution
/*
Brute force-> replace 1 character of startword and find it in wordlist, 
if in, take it and find words to reach the target word by transforming a character 
*/

class Node{
public: 
    string str;
    int level;
    Node(){}
    Node(string data,int lev){
        this->str=data;
        this->level=lev;
    }
};

class Solution{
public:
    // BFS
    int wordLadderLength(vector<string>& wordlist,string start_word,string end_word){
        // if start word is endword return 0 transformation sequence
        if(start_word==end_word) return 0;

        int m = wordlist.size();

        // add all words to a set
        set<string> st;
        for(int i=0;i<m;i++) st.emplace(wordlist[i]);

        queue<Node> q;
        // add the start word to queue
        q.push(Node(start_word,1));

        // until q is empty
        while(!q.empty()){
            string str = q.front().str;
            int level = q.front().level;
            q.pop();

            // if q has end word, return its seq level
            if(str == end_word) return level;

            // check by transforming each character
            int n = str.size();
            for(int i=0;i<n;i++){
                char originalChar = str[i];
                for(char ch='a';ch<='z';ch++){
                    str[i] = ch;    // replace the character
                    // if exists in set 
                    if(st.find(str)!=st.end()){
                        // add to queue
                        q.push(Node(str,level+1));

                        // remove from set 
                        st.erase(str);
                    }
                
                }
                // replace it with original
                str[i]=originalChar;
            }
        }
        // if target word if not reached 
        return 0;
    }
};

void solve()
{
    // grid
    int m;  // number of words in wordlist
    cin >> m;

    // Adjancency List
    vector<string> wordlist(m,"");
    for(int u=0;u<m;u++){
        string str;
        cin>>str;
        wordlist[u]=str;
    }

    string start_word,end_word;
    cin>>start_word>>end_word;

    Solution s;
    int ans=s.wordLadderLength(wordlist,start_word,end_word);
    cout<<ans<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}