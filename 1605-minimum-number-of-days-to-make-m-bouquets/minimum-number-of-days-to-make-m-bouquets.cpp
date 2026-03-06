class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1, end = 1e9;
        int ans = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int totalFlowers = 0, total = 0;
            for(int i : bloomDay) {
                if(i <= mid) totalFlowers++;
                else totalFlowers = 0;
                if(totalFlowers >= k) {
                    totalFlowers -= k;
                    total++;
                }
            }
            if(total >= m) {
                end = mid - 1;
                ans = mid;
            }
            else start = mid + 1;
        }
        return ans;
    }
};