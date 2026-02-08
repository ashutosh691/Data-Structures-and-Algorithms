class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmaller(heights), next = nextSmaller(heights);
        int ans = -1;
        for(int i = 0; i < heights.size(); ++i) {
            int width = next[i] - prev[i] - 1;
            ans = max(ans, heights[i] * width);
        }    
        return ans;
    }
};