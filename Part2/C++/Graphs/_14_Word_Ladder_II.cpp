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

Find all shortest transformation sequence(s) from startWord to targetWord.
You can return them in any order possible.

Return all the sequence

*/

// Solution
/*
Brute force-> replace 1 character of startword and find it in wordlist, 
if in, take it and find words to reach the target word by transforming a character 

just a little change in algo, instead of storing word and level, store sequence at each level
*/

class Node{
public: 
    vector<string> str;
    int level;
    Node(){}
    Node(vector<string> data,int lev){
        this->str=data;
        this->level=lev;
    }
};

class Solution{
public:
    // BFS
    void wordLadderLength(vector<string>& wordlist,string start_word,string end_word){
        // if start word is endword return 0 transformation sequence
        // if(start_word==end_word) return 0;

        vector<vector<string>> seq;
        int shortestLevel=INT_MAX;


        int m = wordlist.size();

        // add all words to a set
        set<string> st;
        for(int i=0;i<m;i++) st.emplace(wordlist[i]);

        queue<Node> q;
        // add the start word to queue
        q.push(Node({start_word},1));

        // until q is empty
        vector<string> strs_to_be_removed;  // delete words from set after whole level is completed
        while (!q.empty()) {
            vector<string> sequence = q.front().str;
            int level = q.front().level;
            q.pop();

            // Get the last word in the current sequence
            string str = sequence.back();

            // If the current sequence contains the end word
            if (str == end_word) {
                if (level <= shortestLevel) {
                    shortestLevel = level;
                    seq.push_back(sequence);
                }
                continue;  // Continue to find other shortest sequences
            }

            // If the current level exceeds the shortest level found, break out of the loop
            if (level > shortestLevel) break;

            // Check by transforming each character of the current word
            int n = str.size();
            for (int i = 0; i < n; i++) {
                char originalChar = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (str[i] == ch) continue;  // Skip if the character is the same

                    str[i] = ch;  // Replace the character

                    // If the transformed word exists in the set
                    if (st.find(str) != st.end()) {
                        sequence.push_back(str);  // Add it to the sequence
                        q.push(Node(sequence, level + 1));
                        sequence.pop_back();  // Remove the word to try other transformations

                        strs_to_be_removed.push_back(str);  // Mark this word for removal
                    }
                }
                // Revert the change
                str[i] = originalChar;
            }

            // After processing the current level, remove the used words from the set
            if (!q.empty() && q.front().level > level) {
                for (const auto& word : strs_to_be_removed) {
                    st.erase(word);
                }
                strs_to_be_removed.clear();
            }
        }

        for(int i=0;i<seq.size();i++){
            for(auto it: seq[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        // if target word if not reached 
        // return 0;
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
    s.wordLadderLength(wordlist,start_word,end_word);
    
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