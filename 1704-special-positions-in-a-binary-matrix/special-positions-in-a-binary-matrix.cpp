class Solution {
public:
    bool check(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        int n1r = 0, n1c = 0;
        for(int i = 0; i < n; ++i) 
            if(mat[i][c] == 1) n1c++;
        for(int i = 0; i < m; ++i)
            if(mat[r][i] == 1) n1r++;
        return n1r == 1 && n1c == 1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0; i < mat.size(); ++i) 
            for(int j = 0; j < mat[i].size(); ++j)
                if(mat[i][j]) 
                    if(check(mat, i, j)) ++ans;
        return ans;
    }
};