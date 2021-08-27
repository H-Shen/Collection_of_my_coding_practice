class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle;
        bool res = true;
        int new_n = 0;
        while (true) {
            if (cycle.find(n) != cycle.end()) {
                res = false;
                break;
            }
            cycle.insert(n);
            new_n = 0;
            while (n > 0) {
                new_n = new_n + (n % 10) * (n % 10);
                n /= 10;
            }
            if (new_n == 1) {
                break;
            }
            n = new_n;
        }
        return res;
    }
};