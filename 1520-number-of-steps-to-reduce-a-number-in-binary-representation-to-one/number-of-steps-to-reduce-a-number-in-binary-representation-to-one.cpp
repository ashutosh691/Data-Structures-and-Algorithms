class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s != "1") {
            if(s[s.size() - 1] == '1') {
                bool done = false;
                s[s.size() - 1] = '0';
                for(int i = s.size() - 2; i >= 0; --i) {
                    if(s[i] == '0') {
                        done = true;
                        s[i] = '1';
                        break;
                    }
                }
                if(!done) s = "1" + string(s.size(), '0');
            }
            else {
                s = s.substr(0, s.size() - 1);
            }
            ++ans;
        }
        return ans;
    }
};