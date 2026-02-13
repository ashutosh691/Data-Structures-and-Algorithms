class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; ++i) {
            bool br = false;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(abs(st.top()) < abs(asteroids[i])) {
                    st.pop();         
                    continue;
                }
                if(abs(st.top()) == abs(asteroids[i])) {
                    st.pop();         
                }
                br = true;            
                break;
            }
            if(br) continue;
            st.push(asteroids[i]);
        }
        vector<int> res;
        while(!st.empty()) {
            res.emplace_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};