class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> unset;
        int cnt = 0;
        int sum = 0;
        int i = 1;
        while (cnt < n) {
            if (i <= k) {
                if (unset.count(i) == 0) {
                    ++cnt;
                    sum += i;
                    unset.insert(k-i);
                }
                ++i;
            }
            else {
                ++cnt;
                sum += i;
                ++i;
            }
        }
        return sum;
    }
};