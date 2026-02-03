class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mnele = abs(nums[0]);
        vector<int> freq(1e5, 0);
        for(auto i : nums) freq[i + mnele]++;
        vector<int> res;
        while(k--){
            int mx = -1, mxfreq = INT_MIN;
            for(int i = 0; i < freq.size(); ++i) {
                if(freq[i] > mxfreq) {
                    mxfreq = freq[i];
                    mx = i;
                }
            }
            freq[mx] = 0;
            res.push_back(mx - mnele);
        }
        return res;
    }
};