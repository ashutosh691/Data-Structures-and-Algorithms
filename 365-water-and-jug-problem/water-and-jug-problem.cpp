class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int z = x + y;
        vector<bool> visited(z + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int dir[] = {x, -x, y, -y};
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(t == target) return true;
            for(int i = 0; i < 4; ++i) {
                int s = t + dir[i];
                if(s >= 0 && s <= z && !visited[s]) q.push(s), visited[s] = true;
            }
        }
        return false;
    }
};