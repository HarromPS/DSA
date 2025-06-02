package Java.Recursion;

public class _6_isValidSudoku {
    public static int fill(int board[][], int row, int col, int digit) {
        for(int i=0;i<board.length;i++){
            if (board[row][i] == digit && i != col) return 0;
            if (board[i][col] == digit && i != row) return 0;
            
            // Check the 3x3 sub-grid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == digit && (subRow != row || subCol != col)) return 0;
        }
        return 1;
    }

    public static int solve(int sudoku[][]) {
        // iterate the sudoku
        for (int i = 0; i < sudoku.length; i++) {
            for (int j = 0; j < sudoku.length; j++) {
                // check if a cell is empty
                if (sudoku[i][j] == 0) {
                    if (fill(sudoku, i, j, sudoku[i][j]) == 1) {
                        // if no solution is returned from putting all possible digits in loop
                        return 0;
                    }
                }
            }
        }
        // found a solution
        return 1;
    }

    // just check if the current sudoku follow all its rules
    public static void main(String[] args) {
        int sodoku[][] = {
                { 0, 8, 7, 6, 5, 4, 3, 2, 1 },
                { 2, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 3, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 4, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 5, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 6, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 7, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 8, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 9, 0, 0, 0, 0, 0, 0, 0, 0 }
        };
        System.out.println((solve(sodoku) == 1)?"Yes":"No");
       
    }
}
