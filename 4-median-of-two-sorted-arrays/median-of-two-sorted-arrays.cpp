class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;
        int l = (n + 1) / 2;
        int start = 0, end = n1;
        while(start <= end) {
            int mid1 = start + (end - start) / 2, mid2 = l - mid1;
            int l1 = INT_MIN, l2 = l1, r1 = INT_MAX, r2 = r1;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1) 
                return (n % 2 != 0 ? max(l1, l2) : (double)(max(l1, l2) + min (r1, r2)) / 2.0);
            if(l1 > r2) end = mid1 - 1;
            else start = mid1 + 1;
        }
        return 0;
    }
};