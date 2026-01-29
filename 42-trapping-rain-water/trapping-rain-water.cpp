class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = height[0], r = height[n - 1];
        int i = 0, j = n - 1;
        while(i < j) {
            l = max(l, height[i]);
            r = max(r, height[j]);
            if(height[i] < height[j]) {
                ans += l - height[i];
                i++; 
            } 
            else {
                ans += r - height[j];
                j--;
            }
        }
        return ans;
    }
};