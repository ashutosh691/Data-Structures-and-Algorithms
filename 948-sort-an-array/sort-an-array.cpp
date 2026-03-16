class Solution {
public:

    void merge(vector<int>& nums, int l, int r, int m) {
        int s1 = m - l + 1, s2 = r - m;
        vector<int> t1(s1), t2(s2);

        for(int i = 0; i < s1; ++i) t1[i] = nums[i + l];
        for(int i = 0; i < s2; ++i) t2[i] = nums[i + m + 1];

        int i = 0, j = 0;

        while(i < s1 && j < s2) 
            if(t1[i] < t2[j]) nums[l++] = t1[i++];
            else nums[l++] = t2[j++];

        while(i < s1) nums[l++] = t1[i++];
        while(j < s2) nums[l++] = t2[j++];
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int m = l + (r - l) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        
        merge(nums, l, r, m);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};