package Java.Recursion;

public class _6_Sudoku_solver_one_soln {
    public static int fill(int sudoku[][], int row, int col, int digit) {
        for (int i = 0; i < sudoku.length; i++) {
            // check the row contains the same digit
            if (sudoku[row][i] == digit) {
                return 0;
            }

            // check the column contains the same digit
            if (sudoku[i][col] == digit) {
                return 0;
            }

            // check if the board contains same digit
            if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) {
                return 0;
            }

        }
        return 1;
    }

    public static int solve(int sudoku[][]) {
        // iterate the sudoku
        for (int i = 0; i < sudoku.length; i++) {
            for (int j = 0; j < sudoku.length; j++) {

                // check if a cell is empty
                if (sudoku[i][j] == 0) {

                    // start filling from 1
                    for (int d = 1; d <= 9; d++) {
                        // check if we can fill the empty space by looking around
                        if (fill(sudoku, i, j, d) == 1) {
                            sudoku[i][j] = d;
                            int res = solve(sudoku);

                            // no need
                            if (res == 1) {
                                // we found a solution by putting digit d
                                // so move to next enpty cell by returning true
                                return 1;
                            }

                            else {
                                // remove current digit to refill with next digit
                                sudoku[i][j] = 0;
                            }
                        }
                    }
                    // if no solution is returned from putting all possible digits in loop
                    return 0;
                }

            }
        }

        // found a solution
        return 1;
    }

    public static void main(String[] args) {
        // Rules
        /*
         * 1. digit 1-9 only once in a row
         * 2. digit 1-9 only once in a col
         * 3. digit 1-9 only once in 3x3 board
         */

        int temp[][] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        int sodoku[][] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        

        int res = solve(sodoku);
        for(int i=0;i<sodoku.length;i++){
            for(int j=0;j<sodoku.length;j++){
                if(temp[i][j]==0){
                    System.out.print(sodoku[i][j]+". ");
                }
                else{
                    System.out.print(sodoku[i][j]+"  ");
                }
            }
            System.out.println();
        }
        if (res == 1) {
            System.out.println("Yes Solvable");
        } else {
            System.out.println("Not solvable");
        }
    }
}
