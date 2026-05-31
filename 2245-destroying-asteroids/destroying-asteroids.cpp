class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(auto i : asteroids) if(i <= mass) mass += i; else return false;
        return true;
    }
};