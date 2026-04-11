class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0, end = matrix.size() - 1;
        int n = matrix[0].size();
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                int low = 0, high = n - 1;
                while(low <= high) {
                    int cen = low + (high - low) / 2;
                    if(matrix[mid][cen] == target) return true;
                    if(matrix[mid][cen] > target) high = cen - 1;
                    else low = cen + 1;
                }
                return false;
            }
            else if(target >= matrix[mid][0]) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};