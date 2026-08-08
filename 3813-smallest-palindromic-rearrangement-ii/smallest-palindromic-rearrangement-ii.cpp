class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddCharIdx = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                oddCount++;
                oddCharIdx = i;
            }
        }
        if (oddCount > 1) return "";

        vector<int> half(26, 0);
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            halfLen += half[i];
        }

        const long long CAP = 2000000LL; // safely above max k (1e6)

        auto comb = [&](long long nn, long long cc) -> long long {
            if (cc < 0 || cc > nn) return 0;
            cc = min(cc, nn - cc);
            long long result = 1;
            for (long long i = 1; i <= cc; i++) {
                result = result * (nn - cc + i) / i;
                if (result > CAP) return CAP + 1;
            }
            return result;
        };
        
        auto countPerms = [&](vector<int>& counts) -> long long {
            long long remaining = 0;
            for (int c : counts) remaining += c;
            long long result = 1;
            for (int c : counts) {
                if (c == 0) continue;
                long long C = comb(remaining, c);
                result *= C;
                if (result > CAP) return CAP + 1;
                remaining -= c;
            }
            return result;
        };

        long long totalPerms = countPerms(half);
        if ((long long)k > totalPerms) return "";

        string halfStr;
        long long kk = k;
        vector<int> remaining = half;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (remaining[c] == 0) continue;
                remaining[c]--;
                long long perms = countPerms(remaining);
                if (perms >= kk) {
                    halfStr.push_back('a' + c);
                    break;
                } else {
                    kk -= perms;
                    remaining[c]++;
                }
            }
        }

        string result = halfStr;
        if (oddCharIdx != -1) result.push_back('a' + oddCharIdx);
        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        result += rev;

        return result;
    }
};