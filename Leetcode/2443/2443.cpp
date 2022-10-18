class Solution {
public:
    inline int getReverse(int k) const {
        if (k < 10) return k;
        int ans = 0;
        while (k > 0) {
            ans = ans * 10 + (k % 10);
            k /= 10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        int temp;
        for (int i = 0; i <= num; ++i) {
            temp = getReverse(i);
            if (i + temp == num) {
                return true;
            }
        }
        return false;
    }
};