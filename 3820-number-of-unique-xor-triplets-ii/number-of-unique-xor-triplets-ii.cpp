class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1) return 1;
        unordered_set<int> st;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                st.insert(nums[i] ^ nums[j]);
        vector<bool> seen(2048, false);
        for(auto x : st)
            for(int i = 0; i < n; ++i) 
                seen[x ^ nums[i]] = true;
        for(auto i : seen) if(i) ++ans;
        return ans;
    }
};