class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> temp = mat;
        k = k % n;
        for(int i = 0; i < m; ++i) {
            if(i & 1) {
                reverse(temp[i].begin(), temp[i].end());
                reverse(temp[i].begin(), temp[i].begin() + k);
                reverse(temp[i].begin() + k, temp[i].end());
            }
            else {
                reverse(temp[i].begin(), temp[i].begin() + k);
                reverse(temp[i].begin() + k, temp[i].end());
                reverse(temp[i].begin(), temp[i].end());
            }
        }
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] != temp[i][j]) return false;
        return true;
    }
};