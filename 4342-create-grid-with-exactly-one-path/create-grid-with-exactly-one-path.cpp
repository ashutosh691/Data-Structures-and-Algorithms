class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        res.push_back(string(n, '.'));
        m--;
        while (m--)
            res.push_back(string(n - 1, '#') + string(1, '.'));
        return res;
    }
};