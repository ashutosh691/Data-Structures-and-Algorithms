class Solution {
public:
    int numSquares(int n) {
        int sz = sqrt(n);
        vector<int> nums(sz + 1);
        for(int i = 0; i <= sz; ++i)
            nums[i] = i * i;
        queue<pair<int, int>> q;
        vector<int> vis(n + 1, 0);
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for(int i = 1; i <= sz; ++i) {
                int sum = a + nums[i];
                if(sum == n)
                    return b + 1;
                if(sum < n && !vis[sum]) {
                    vis[sum] = 1;
                    q.push({sum, b + 1});
                }
                if(sum > n)
                    break;
            }
        }
        return -1;
    }
};