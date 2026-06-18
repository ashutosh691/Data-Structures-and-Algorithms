class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double diff = abs(30.0 * hour - 5.5 * minutes);
        return min(diff, 360.0 - diff);
    }
};