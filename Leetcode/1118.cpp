class Solution {
public:
    bool isLeap(int y) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            return true;
        }
        return false;
    }
    int numberOfDays(int Y, int M) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (M != 2) return days[M-1];
        return isLeap(Y) ? 29 : 28;
    }
};