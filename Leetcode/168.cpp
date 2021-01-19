class Solution {
public:
    string convertToTitle(int n) {
        constexpr int N = 26;
        string res;
        while (n > 0) {
            res = (char)((n - 1) % N + 'A') + res;
            n = (n - 1) / N;
        }
        return res;
    }
};