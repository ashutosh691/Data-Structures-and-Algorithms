class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    int t;
    void traverse(int i, int sum, vector<int> cnums) {
        if(sum == t) {
            res.push_back(cnums);
            return;
        }
        if(i >= nums.size()) return;
        if(sum > t) return;
        traverse(i + 1, sum, cnums);
        cnums.push_back(nums[i]);
        traverse(i, sum + nums[i], cnums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums.insert(nums.end(), candidates.begin(), candidates.end());
        t = target;
        traverse(0, 0, {});
        return res;
    }
};