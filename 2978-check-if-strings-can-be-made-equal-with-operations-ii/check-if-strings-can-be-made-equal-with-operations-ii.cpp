class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string even1 = "", odd1 = "", even2 = "", odd2 = "";
        int n = s1.size();
        for(int i = 0; i < n; i += 2) even1 += s1[i], even2 += s2[i];
        for(int i = 1; i < n; i += 2) odd1 += s1[i], odd2 += s2[i];
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        return even1 == even2 && odd1 == odd2;
    }
};