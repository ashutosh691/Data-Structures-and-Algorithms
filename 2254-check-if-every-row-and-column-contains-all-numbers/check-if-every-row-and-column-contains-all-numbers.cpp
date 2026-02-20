class Solution {
public:
    bool all(vector<vector<int>>& matrix, int in, int n) {
        unordered_set<int> mp1, mp2;
        for(int i = 0; i < n; ++i)  {
            if(mp1.count(matrix[in][i])) return false;
            if(mp2.count(matrix[i][in])) return false;
            mp1.insert(matrix[in][i]);
            mp2.insert(matrix[i][in]);
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i) 
            if(!all(matrix, i, n)) return false;
        return true;
    }
};