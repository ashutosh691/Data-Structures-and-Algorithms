class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int n = nums.size(), c = 0;
        for(int i = 0; i < n; ++i)
        {
            minHeap.push(nums[i]);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};