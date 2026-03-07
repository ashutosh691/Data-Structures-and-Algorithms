/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int st = 1, end = n - 2;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int m1 = mountainArr.get(mid), m2 = mountainArr.get(mid + 1);
            if(m1 < m2) st = mid + 1;
            else end = mid - 1;
        }
        int peak = st;
        st = 0, end = peak;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int m1 = mountainArr.get(mid), s1 = mountainArr.get(st);
            if(m1 == target) return mid;
            if(m1 > target) end = mid - 1;
            else st = mid + 1;
        }
        st = peak + 1, end = n - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int m1 = mountainArr.get(mid), s1 = mountainArr.get(st);
            if(m1 == target) return mid;
            if(m1 > target) st = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};