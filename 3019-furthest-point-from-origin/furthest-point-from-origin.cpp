class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = count(moves.begin(), moves.end(), 'L'), r = count(moves.begin(), moves.end(), 'R');
        int ans = 0, maj = l > r ? -1 : 1;
        for(auto i : moves) 
            i == 'L' ? --ans : i == 'R' ? ++ans : ans += maj;
        return abs(ans);
    }
};