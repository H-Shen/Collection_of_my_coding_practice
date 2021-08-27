class Solution {
public:
    bool containsZero(int k) {
        while (k > 0) {
            if (k % 10 == 0) return true;
            k /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i, j;
        for (i = 1; i <= n - 1; ++i) {
            j = n - i;
            if (!containsZero(i) && !containsZero(j)) {
                return vector<int>{i, j};
            }
        }
        return vector<int>();
    }
};