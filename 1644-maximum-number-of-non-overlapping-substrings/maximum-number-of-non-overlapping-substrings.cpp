class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Store the first and last occurrence of every character.
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Build the smallest valid interval for each character.
        for (int i = 0; i < 26; i++) {
            if (last[i] == -1)
                continue;

            int l = first[i];
            int r = last[i];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                int x = s[j] - 'a';

                // This character started before our interval.
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Include all occurrences of this character.
                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // Earliest ending interval should be selected first.
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        // Greedily select non-overlapping intervals.
        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};