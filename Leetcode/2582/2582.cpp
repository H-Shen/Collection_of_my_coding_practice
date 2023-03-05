class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 0;
        bool right = true;
        ++time;
        while (time--) {
            if (right) {
                ++ans;
            }
            else {
                --ans;
            }
            if (ans == n && right) {
                right = false;
            }
            if (ans == 1 && !right) {
                right = true;
            }
        }
        return ans;
    }
};