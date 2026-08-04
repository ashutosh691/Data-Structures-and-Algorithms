class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> st;
        vector<int> res;
        int mn = INT_MAX, mx = INT_MIN;
        for(auto i : nums) {
            mn = min(mn, i);
            mx = max(i, mx);
            st.insert(i);
        }
        for(int i = mn + 1; i < mx; ++i) 
            if(!st.count(i)) 
                res.emplace_back(i);
        return res;
    }
};