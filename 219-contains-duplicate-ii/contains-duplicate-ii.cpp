class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_set<int> s;
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            if(s.count(arr[i])) return true;
            s.insert(arr[i]);
            if(i - k >= 0) s.erase(arr[i - k]);
        }
        return false;
    }
};
