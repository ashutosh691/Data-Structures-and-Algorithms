class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long st = 1, end = m * n;
        while(st < end) {
            int mid = st + (end - st) / 2;
            long long count = 0;
            for(int i = 1; i <= m; ++i) 
                count += min(n, mid / i);
            if(count >= k) end = mid;
            else st = mid + 1;
        }
        return st;
    }
};