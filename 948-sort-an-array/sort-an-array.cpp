class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int random = (rand() % (r - l + 1)) + l;
        swap(nums[random], nums[r]);
        int pivot = nums[r];
        int i = l, j = l - 1;
        while(i < r) {
            if(nums[i] < pivot) swap(nums[i], nums[++j]);
            ++i;
        }
        swap(nums[j + 1], nums[r]);
        return j + 1;
    }
    void quickSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }
};