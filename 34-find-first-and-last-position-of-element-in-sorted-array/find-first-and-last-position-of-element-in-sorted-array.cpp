class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int key) {
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == key) {
                first = mid;
                right = mid - 1;
            }
            else if(nums[mid] > key) 
                right = mid - 1;
            else left = mid + 1;
        }
        if(first == -1) {
            return {-1, -1};
        }
        left = first, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == key) {
                last = mid;
                left = mid + 1;
            }
            else if(nums[mid] > key) 
                right = mid - 1;
            else left = mid + 1;
        }
        return {first, last};
    }
};