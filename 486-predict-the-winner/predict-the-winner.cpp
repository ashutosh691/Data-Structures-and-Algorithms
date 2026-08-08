class Solution {
public:
    int maxSc(vector<int>& nums, int l, int r, int chance) {
        if (l > r) return 0;
        if (chance == 1) {
            return max(
                nums[l] + maxSc(nums, l + 1, r, -1),
                nums[r] + maxSc(nums, l, r - 1, -1)
            );
        } else {
            return min(
                -nums[l] + maxSc(nums, l + 1, r, 1),
                -nums[r] + maxSc(nums, l, r - 1, 1)
            );
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int ans = 0;
        ans = maxSc(nums, 0, nums.size() - 1, 1);
        return ans >= 0;
    }
};