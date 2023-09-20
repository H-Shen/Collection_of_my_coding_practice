class Solution {
public:
    inline
    bool check(int n) {
        string s = to_string(n);
        int length = (int)s.size();
        if (length & 1) return false;
        int a = 0, b = 0;
        for (int i = 0, j = length-1; i < j; ++i, --j) {
            a += (int)(s[i] - '0');
            b += (int)(s[j] - '0');
        }
        return a == b;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; ++i) {
            if (check(i)) ++cnt;
        }
        return cnt;
    }
};