class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), n = piles.size();
        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long temp = 0;
            for(int i = 0; i < n; ++i) temp += ceil(piles[i] / (double)mid);
            if(temp <= h) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};