class Solution {
    vector<vector<string>> res;
    vector<vector<char>> grid;
public:
    bool isSafe(int row, int col, int n) {
        for(int i = 0; i < row; ++i) //horizontal and vertical
            if(grid[row][i] == 'Q' || grid[i][col] == 'Q') return false;

        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) //left diagonal
            if(grid[i][j] == 'Q') return false;

        for(int i = row, j = col; i >= 0 && j < n; --i, ++j) //right diagonal
            if(grid[i][j] == 'Q') return false;

        return true;
    }

    void nQueens(int in, int n) {
        if(in == n) {
            vector<string> st;

            for(int i = 0; i < n; ++i) {
                string temp = "";
                for(int j = 0; j < n; ++j) 
                    temp += grid[i][j];
                st.emplace_back(temp);
            }

            res.emplace_back(st);
            return;
        }

        for(int i = 0; i < n; ++i) 
            if(isSafe(in, i, n)) {
                grid[in][i] = 'Q';
                nQueens(in + 1, n);
                grid[in][i] = '.';
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char>(n, '.'));
        nQueens(0, n);
        return res;
    }
};