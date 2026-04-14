class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, char ch) {
        for(int k = 0; k < 9; ++k) {
            if(board[i][k] == ch || board[k][j] == ch) return false;
            int r = i / 3 * 3 + k / 3, c = j / 3 * 3 + k % 3;
            if(board[r][c] == ch) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int i, int j) {
        if(i == 9) return true;
        if(j == 9) return helper(board, i + 1, 0);
        if(board[i][j] != '.') return helper(board, i, j + 1);
        for(char k = '1'; k <= '9'; ++k) 
            if(isSafe(board, i, j, k)) {
                board[i][j] = k;
                if(helper(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};