package Java.Trie;

import java.io.*;
import java.util.*;

// define a trie stucture
class TrieNode {
    // create a arraylist pointers to child TrieNodes to store 26 letters
    public TrieNode children[] = new TrieNode[26];

    // wordend boolean. sets inserted string's end
    public boolean wordEnd;

    // constructor to create a TrieNode
    TrieNode() {
        // initially make all the string openings as null
        for (int i = 0; i < 26; i++) {
            children[i] = null;
        }

        // make its string as false initially
        wordEnd = false;
    }
}


public class TrieDataStruct {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void solve(FastReader sc) {
        // create a root node
        TrieNode root = new TrieNode();

        // get some strings
        String words[] = {"and","ant","dad"};
        
        // insert into the trie
        for(int i=0;i<words.length;i++){
            insertTrie(root,words[i]);
            }
            
            // search words
        String searchwords[] = {"and","antd","dad"};
        for(int i=0;i<searchwords.length;i++){
            boolean res = searchTrie(root,searchwords[i]);
            if(res==true){
                System.out.println("Found: "+searchwords[i]);
            }else{
                System.out.println("Not Found: "+searchwords[i]);
            }
        }
    }

    // inserting into trie
    public static void insertTrie(TrieNode root, String word) {
        // create a temp tracker to root Trie node
        TrieNode curr = root;

        // iterate through the word and insert its letters one by one to the trie
        for (int i = 0; i < word.length(); i++) {
            // check if there already exists letter, if not, then insert, else move to next
            // child pointer
            if (curr.children[word.charAt(i) - 'a'] == null) {
                // create a new Trie Child and point curr child's letter(in forms of index) to
                // newly created node
                TrieNode newNode = new TrieNode();
                curr.children[word.charAt(i) - 'a'] = newNode;
            }
            // move to next child pointer
            curr = curr.children[word.charAt(i) - 'a'];
        }

        // wordend at the end of the string for this insertion marks ending of the
        // string
        curr.wordEnd = true;
        System.out.println("Inserted: " + word);
    }

    // search trie
    public static boolean searchTrie(TrieNode root, String word) {
        // create a temp tracker to root Trie node
        TrieNode curr = root;

        // iterate through the word
        for (int i = 0; i < word.length(); i++) {
            // check if child node is null before end of the string
            if (curr.children[word.charAt(i) - 'a'] == null) {
                return false;
            }
            // move to next child pointer
            curr = curr.children[word.charAt(i) - 'a'];
        }

        // at the end of the string, check if trie's same string has wordend for this
        // string
        return (curr.wordEnd == true ? true : false);
    }

    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        FastReader sc = new FastReader(System.in);
        // int test = sc.nextInt();
        // while (test-- > 0) {
        //     solve(sc);
        // }
        solve(sc);
    }
}
