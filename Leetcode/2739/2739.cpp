class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            ans += 50;
            mainTank -= 5;
            if (additionalTank > 0) {
                ++mainTank;
                --additionalTank;
            }
        }
        ans += mainTank * 10;
        return ans;
    }
};