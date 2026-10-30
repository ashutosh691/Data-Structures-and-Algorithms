class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1'000'000'007;

        sort(inventory.begin(), inventory.end(), greater<int>());

        int n = inventory.size();
        long long ans = 0;

        for (int i = 0; i < n && orders > 0; ++i) {
            long long curr = inventory[i];
            long long next = (i + 1 < n) ? inventory[i + 1] : 0;

            long long count = i + 1;
            long long diff = curr - next;
            long long total = count * diff;

            long long take = min((long long)orders, total);
            long long levels = take / count;
            long long remainder = take % count;

            long long high = curr;
            long long low = curr - levels;

            long long sum = ((high * (high + 1) / 2)
                           - (low * (low + 1) / 2)) % MOD;

            ans = (ans + sum * count) % MOD;

            ans = (ans + remainder * low) % MOD;

            orders -= take;
        }

        return ans;
    }
};