class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = 0;
        x = abs(30*hour-(5.5)*minutes);
        x = min(x,360-x);
        return x;
    }
};