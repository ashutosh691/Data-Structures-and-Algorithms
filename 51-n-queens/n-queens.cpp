class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<vector<char>>& mat, int& row, int& col, int& n) {
        for(int i = 0; i < n; ++i) //horizontal and vertical
            if(mat[row][i] == 'Q' || mat[i][col] == 'Q') return false;
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) //left diagonal
            if(mat[i][j] == 'Q') return false;
        for(int i = row, j = col; i >= 0 && j < n; --i, ++j) //right diagonal
            if(mat[i][j] == 'Q') return false;
        return true;
    }
    void nQueens(vector<vector<char>>& mat, int n, int x) {
        if(x == n) {
            vector<string> temp;
            for(int i = 0; i < n; ++i) {
                string t = "";
                for(int j = 0; j < n; ++j) {
                    t += mat[i][j];
                }
                temp.emplace_back(t);
            }
            ans.emplace_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(isSafe(mat, x, i, n)) {
                mat[x][i] = 'Q';
                nQueens(mat, n, x + 1);
                mat[x][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> mat(n, vector<char>(n, '.'));
        nQueens(mat, n, 0);
        return ans;
    }
};