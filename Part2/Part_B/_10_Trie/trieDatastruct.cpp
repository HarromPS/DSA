#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// define a trie stucture
typedef struct TrieNode{
    // create a arraylist pointers to child TrieNodes to store 26 letters 
    TrieNode* children[26];

    // wordend boolean-> sets inserted string's end 
    bool wordEnd;

    // constructor to create a TrieNode
    TrieNode(){
        // initially make all the string openings as null
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

        // make its string as false initially 
        wordEnd = false;
    }
}TrieNode;

// inserting into trie 
void insertTrie(TrieNode* root, string word){
    // create a temp tracker to root Trie node
    TrieNode* curr = root;

    // iterate through the word and insert its letters one by one to the trie
    for(int i=0;i<word.size();i++){
        // check if there already exists letter, if not, then insert, else move to next child pointer
        if(curr->children[word[i]-'a']==NULL){
            // create a new Trie Child and point curr child's letter(in forms of index) to newly created node
            TrieNode* newNode = new TrieNode();
            curr->children[word[i]-'a'] = newNode;
        }
        // move to next child pointer
        curr = curr->children[word[i]-'a'];
    }

    // wordend at the end of the string for this insertion marks ending of the string
    curr->wordEnd = true;
    cout<<"Inserted: "<<word<<endl;
}

// search trie
bool searchTrie(TrieNode* root, string word){
    // create a temp tracker to root Trie node
    TrieNode* curr = root;

    // iterate through the word 
    for(int i=0;i<word.size();i++){
        // check if child node is null before end of the string 
        if(curr->children[word[i]-'a']==NULL){
            return false;
        }
        // move to next child pointer
        curr = curr->children[word[i]-'a'];
    }

    // at the end of the string, check if trie's same string has wordend for this string
    return (curr->wordEnd == true?true:false);
}

void solve()
{
    // create a root node
    TrieNode* root = new TrieNode();

    // get some strings
    vector<string> words = {"and","ant","dad"};

    // insert into the trie
    for(int i=0;i<words.size();i++){
        insertTrie(root,words[i]);
    }

    // search words
    vector<string> searchwords={"and","antd","dad"};
    for(int i=0;i<searchwords.size();i++){
        bool res = searchTrie(root,searchwords[i]);
        if(res==true){
            cout<<"Found: "<<searchwords[i]<<endl;
        }else{
            cout<<"Not Found: "<<searchwords[i]<<endl;
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
