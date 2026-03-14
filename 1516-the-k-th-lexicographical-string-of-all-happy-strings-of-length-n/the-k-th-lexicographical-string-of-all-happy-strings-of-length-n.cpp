class Solution {
public:
    void getall(vector<string>& res, int n, string s) {
        if(s.size() == n) {
            res.push_back(s);
            return;
        }
        if(s.size() != 0) {
            int m = s.size();
            if(s[m - 1] == 'a') {
                getall(res, n, s + "b");
                getall(res, n, s + "c");
            }
            else if(s[m - 1] == 'b') {
                getall(res, n, s + "a");
                getall(res, n, s + "c");
            }
            else {
                getall(res, n, s + "a");
                getall(res, n, s + "b");
            }
        }
        else {
            getall(res, n, "a");
            getall(res, n, "b");
            getall(res, n, "c");
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        getall(res, n, "");
        if(k > res.size()) return "";
        sort(res.begin(), res.end());
        return res[k - 1];
    }
};