class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int mid = static_cast<int>(sqrt(static_cast<double>(num)) + 1);
        unordered_set<int> factors;
        for (; mid > 0; --mid) {
            if (num % mid == 0) {
                factors.insert(num / mid);
                factors.insert(mid);
            }
        }
        factors.erase(num);
        return accumulate(factors.begin(), factors.end(), static_cast<int>(0)) == num;
    }
};