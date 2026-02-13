class Solution {
public:
    void utils(vector<string>& res, string temp, int n, int open, int close) {
        if(temp.size() == 2 * n) {
            res.push_back(temp);
            return;
        }
        if(open < n) utils(res, temp + "(", n, open + 1, close);
        if(close < open) utils(res, temp + ")", n, open, close + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        utils(res, "", n, 0, 0);
        return res;
    }
};