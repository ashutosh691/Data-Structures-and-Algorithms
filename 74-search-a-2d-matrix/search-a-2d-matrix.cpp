class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size() - 1;
        int s = 0, e = matrix.size() - 1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(target >= matrix[m][0] && target <= matrix[m][n]){
                int start = 0, end = n;
                while(start <= end) {
                    int mid = start + (end - start) / 2;
                    if(matrix[m][mid] == target) return true;
                    if(matrix[m][mid] < target) start = mid + 1;
                    else end = mid - 1;
                } 
                return false;
            }
            else if(target >= matrix[m][0]) s = m + 1;
            else e = m - 1;
        }
        return false;
    }
};