class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> s;
        for(auto& i : obstacles) s.insert({i[0], i[1]});

        int ans = 0, x = 0, y = 0;
        int dir = 0;
        for(auto i : commands) {
            if(i == -2) dir = (dir + 3) % 4;
            else if(i == -1) dir = (++dir) % 4;
            else {
                while(i--) {
                    pair<int, int> prev = {x, y};
                    switch(dir) {
                        case 0 : ++y;
                                break;
                        case 1 : ++x;
                                break;
                        case 2 : --y;
                                break;
                        default : --x;
                    }
                    if(s.count({x, y})) {
                        x = prev.first, y = prev.second;
                        break;
                    }
                }
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};