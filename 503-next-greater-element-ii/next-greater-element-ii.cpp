class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i = 2 * n - 1; i >= 0; --i) {
            int in = i % n;
            while(!st.empty() && nums[st.top()] <= nums[in]) st.pop();
            if(!st.empty()) res[in] = nums[st.top()];
            st.push(in);
        }
        return res;
    }
};