package Java.Recursion;

import java.util.Scanner;

public class _5_N_Queens{
    public static int count=0;

    // IMP NOTE: this function check safe place for col by col filling method
    public static int fill(int row,int col, int n,int matrix[][]){
        // check in only 4 directions from current position

        // 0 - can't fill, 1 - can fill
        
        // upward(north)
        int i=row, j=col;
        while(i>=0){
            if(matrix[i][j]==1){
                return 0;
            }
            i--;
        }

        // south west
        i=row; j=col;
        while(i<n && j>=0){
            if(matrix[i][j]==1){
                return 0;
            }
            i++;
            j--;
        }

        // west
        i=row; j=col;
        while(j>=0){
            if(matrix[i][j]==1){
                return 0;
            }
            j--;
        }

        // nort west
        i=row; j=col;
        while(i>=0 && j>=0){
            if(matrix[i][j]==1){
                return 0;
            }
            i--;
            j--;
        }

        return 1;
    }
    public static void solveNQueens(int col,int matrix[][]){
        // base condition
        if(col>=matrix.length){
            // print the chess board
            for(int i=0;i<matrix.length;i++){
                for(int j=0;j<matrix.length;j++){
                    System.out.print(matrix[i][j]+" ");
                }
                System.out.println();
            }
            System.out.println();
            count+=1;
            return;
        }

        // iterate for each row for this column
        for(int row = 0;row<matrix.length;row++){
            // check if fillable
            if(fill(row,col,matrix.length,matrix)==1){
                // then put the queen at row x col
                matrix[row][col] = 1;

                // fill the next column
                solveNQueens(col+1, matrix);

                // after back track, remove queen
                matrix[row][col] = 0;
            }
        }
    }
    public static void solve(int n){
        int matrix[][] = new int[n][n];
        
        // 0-empty, 1-Queen 

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // initially empty
                matrix[i][j]=0;
            }
        }
        // start from 0th column and recursively track the metrix for solution
        solveNQueens(0, matrix);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter N: ");
        int n = sc.nextInt();

        solve(n);
        System.out.print("The number of ways N queens can be placed in nxn chessboard without attacking each other is: "+count+"\n");

        sc.close();

    }   
}