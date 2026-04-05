class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto i : moves) {
            if(i == 'U') ++x;
            else if(i == 'D') --x;
            else if(i == 'L') --y;
            else ++y;
        }
        return x == 0 and y == 0;
    }
};