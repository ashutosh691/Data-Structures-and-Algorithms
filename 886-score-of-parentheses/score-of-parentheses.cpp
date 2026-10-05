class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0;
        char prev = ')';
        for(auto ch : s) {
            if(ch == '(') {
                st.push(ch);
            }
            else {
                st.pop();
                if(prev == '(') ans += 1 << st.size();
            } 
            prev = ch;
        }
        return ans;
    }
};