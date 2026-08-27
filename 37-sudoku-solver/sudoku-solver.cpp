class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit)
                return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        // All rows completed
        if (row == 9)
            return true;

        // Move to next row
        if (col == 9)
            return solve(board, row + 1, 0);

        // Already filled cell
        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        // Try digits 1 to 9
        for (char digit = '1'; digit <= '9'; digit++) {

            if (isValid(board, row, col, digit)) {

                // Place digit
                board[row][col] = digit;

                // Recursively solve remaining cells
                if (solve(board, row, col + 1))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};