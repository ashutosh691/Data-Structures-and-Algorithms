class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < n; ++j)
                res[j][i] = matrix[i][j];
        for(int i = 0; i < n; ++i) reverse(res[i].begin(), res[i].end());
        matrix = res;
    }
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] != target[i][j]) return false;
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> temp = mat;
        while(1) {
            if(isEqual(temp, target)) return true;
            rotate(temp);
            if(isEqual(temp, mat)) return false;
        }
        return false;
    }
};