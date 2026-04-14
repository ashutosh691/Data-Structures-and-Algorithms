class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool u1[9][9] = {false}, u2[9][9] = {false}, u3[9][9] = {false};
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] != '.') {
                    int k = i / 3 * 3 + j / 3;  //represents sub boxes
                    int n = board[i][j] - '0' - 1; //conversion of number to 0 based number
                    if(u1[i][n] || u2[j][n] || u3[k][n]) return false;
                    u1[i][n] = u2[j][n] = u3[k][n] = true;
                }
        return true;
    }
};