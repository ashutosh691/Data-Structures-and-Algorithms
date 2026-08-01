class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for(int d = 0; d < m + n - 1; ++d) {
            int r = (d < m ? d : m - 1), c = d - r;
            vector<int> temp;
            while(r >= 0 && c < n) temp.emplace_back(mat[r--][c++]);
            if(d & 1) reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end()); 
        }
        return res;
    }
};