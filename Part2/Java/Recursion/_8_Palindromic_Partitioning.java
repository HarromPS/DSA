package Java.Recursion;

import java.util.ArrayList;

public class _8_Palindromic_Partitioning {
    public static boolean isPalindrome(int start,int end,String s){
        while(start<=end){
            if(s.charAt(start++)!=s.charAt(end--)){
                return false;
            }
        }
        return true;
    }

    public static void solve(String s,int index,ArrayList<String> ds){
        // base case 
        if(index>=s.length()){
            for(int i=0;i<ds.size();i++){
                System.out.print(ds.get(i)+"|");
            }
            System.out.println();
            return ;
        }

        // iterate, partition and check if the partiton is palindrome
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)==true){
                ds.add(s.substring(index,i+1));
                solve(s,i+1,ds);
                ds.remove(ds.size()-1);
            }
        }

    }
    public static void main(String[] args) {
        String s="aabb";
        ArrayList<String> ch = new ArrayList<>();

        // generate all possible partitions
        solve(s,0,new ArrayList<>(ch));
    }   
}
