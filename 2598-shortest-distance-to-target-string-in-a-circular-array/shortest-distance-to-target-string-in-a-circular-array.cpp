class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int first = -1, second = -1, n = words.size();
        bool again = false;
        int i = startIndex, c = 0;
        while(!again) {
            if(words[i] == target) {
                first = c;
                c = 0;
                break;
            }
            ++c;
            i = (i + 1) % n;
            if(i == startIndex) again = true;
        }
        again = false;
        i = startIndex;
        while(!again) {
            if(words[i] == target) {
                second = c;
                break;
            }
            ++c;
            i = (i - 1 + n) % n;
            if(i == startIndex) again = true;
        }
        return min(first, second);
    }
};