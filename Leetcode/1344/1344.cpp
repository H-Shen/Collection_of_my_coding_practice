class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = minutes*6;
        double b = minutes/2.0+30.0*hour;
        while (b > 360) b -= 360;
        return min(abs(a-b), 360-abs(a-b));
    }
};