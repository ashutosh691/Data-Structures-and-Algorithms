class Solution {
public:
    string originalDigits(string s) {
        vector<int> nums(10, 0);
        unordered_map<char, int> mp;
        for(auto i : s) mp[i]++;
        nums[0] = mp['z'];
        nums[2] = mp['w'];
        nums[4] = mp['u'];
        nums[6] = mp['x'];
        nums[8] = mp['g'];
        nums[1] = mp['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = mp['h'] - nums[8];
        nums[5] = mp['f'] - nums[4];
        nums[7] = mp['s'] - nums[6];
        nums[9] = mp['i'] - nums[5] - nums[6] - nums[8];
        string ans = "";
        for(int i = 0; i <= 9; ++i) if(nums[i]) ans += string(nums[i], (i + '0'));
        return ans;
    }
};