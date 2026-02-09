class Solution {
public:
    bool isSafe(vector<vector<char>>& mat, int& row, int& col, int& n) {
        for(int i = 0; i < n; ++i) //horizontal and vertical
            if(mat[row][i] == 'Q' || mat[i][col] == 'Q') return false;
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) //left diagonal
            if(mat[i][j] == 'Q') return false;
        for(int i = row, j = col; i >= 0 && j < n; --i, ++j) //right diagonal
            if(mat[i][j] == 'Q') return false;
        return true;
    }
    void nQueens(vector<vector<string>>& ans, vector<vector<char>>& mat, int& n, int row) {
        if(row == n) {
            vector<string> temp;
            string t = "";
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    t += mat[i][j];
                }
                temp.push_back(t);
                t = "";
            }
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(isSafe(mat, row, i, n)) {
                mat[row][i] = 'Q';
                nQueens(ans, mat, n, row + 1);
                mat[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> mat(n, vector<char>(n));
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < n; ++j)
                mat[i][j] = '.';
        nQueens(ans, mat, n, 0);
        return ans;
    }
};