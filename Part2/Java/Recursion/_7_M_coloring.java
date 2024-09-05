package Java.Recursion;

import java.util.ArrayList;

public class _7_M_coloring{
    public static Boolean isPossible(int adj[][],ArrayList<Integer> colored,int node,int color){
        for(int i=0;i<adj.length;i++){
            // if its a neighbour and its color is same then return false
            if(adj[node][i]==1 && i!=node){
                if(colored.get(i)==color){
                    return false;
                }
            }
        }
        return true;
    }
    public static Boolean Solution(int adj[][], int node, int colors,ArrayList<Integer> colored){
        // base condition 
        if(node>=adj.length){
            return true;        // colored all the nodes with a color 
        }

        // iterate and check with all possible color
        for(int i=1;i<=colors;i++){
            // check if it is possible to color the node or not
            if(isPossible(adj,colored,node,i)==true){
                colored.set(node, i);

                // check if it is possible to color its neighbour nodes 
                if(Solution(adj, node+1, colors,new ArrayList<>(colored))==true){
                    // no need to check further colors to fit, just return
                    return true;
                }

                // else
                colored.set(node, -1);  // just reset its color and check from rest of the colors
            }
        }
        // if cant color n nodes with M colors
        return false;
    }
    public static Boolean solve(int adj[][],int colors){
        ArrayList<Integer> colored = new ArrayList<>();

        // initially all the color is -1 i.e not colored
        for(int i=0;i<adj.length;i++){
            colored.add(-1);
        }

        return Solution(adj,0,colors,new ArrayList<>(colored));
    }
    public static void main(String[] args) {
        int adj[][]={
            {0,1,1,1},
            {1,0,1,1},
            {1,1,0,0},
            {1,1,0,0},
        };
        int m = 2;
        Boolean res = solve(adj,m);
        System.out.println(res?"Yes":"No");
    }
}