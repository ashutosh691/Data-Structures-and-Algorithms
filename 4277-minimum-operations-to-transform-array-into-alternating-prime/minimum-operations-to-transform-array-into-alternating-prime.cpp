class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int MAXN = 200000;
        vector<bool> isPrime(MAXN + 1, true);    
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= MAXN; ++i) 
            if(isPrime[i]) 
                for(int j = i * i; j <= MAXN; j += i) 
                    isPrime[j] = false;

        vector<int> primes;
        for(int i = 2; i <= MAXN; ++i) 
            if(isPrime[i]) primes.push_back(i);

        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; ++i) {
            if(i & 1) {
                if(isPrime[nums[i]]) {
                    if(nums[i] == 2) ans += 2;
                    else ans += 1;
                }
            }
            else {
                if(isPrime[nums[i]]) continue;

                auto it = upper_bound(primes.begin(), primes.end(), nums[i]);

                if(it == primes.end()) continue;

                int next = *it;
                ans += (next - nums[i]);
            }
        }

        return ans;
    }
};