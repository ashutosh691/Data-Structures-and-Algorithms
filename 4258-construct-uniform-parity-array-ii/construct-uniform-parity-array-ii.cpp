class Solution {
public:
    bool same(vector<int>& nums) {
        int p = nums[0] & 1;
        int n = nums.size();
        for(int i = 1; i < n; ++i) if((nums[i] & 1) != p) return false;
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        if(same(nums1)) return true;
        int n = nums1.size();
        set<int> st;
        for(int i : nums1) st.insert(i);
        for(int i = 0; i < n; ++i) 
            if(nums1[i] % 2 == 0)  
                for(int j : st) 
                    if(j >= nums1[i]) return false;
                    else if(j % 2) break;
        return true;
    }
};