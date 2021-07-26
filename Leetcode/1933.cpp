class Solution {
public:
    bool isDecomposable(string s) {
        int n = (int)s.size();
        int counter = 0;
        int temp = 0;
        int length = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++length;
                continue;
            }
            if (s[i] == s[i-1]) {
                ++length;
            }
            else {
                temp = length % 3;
                if (temp == 1) return false;
                else if (temp == 2) ++counter;
                length = 1;
            }
        }
        if (length > 0) {
            temp = length % 3;
            if (temp == 1) return false;
            else if (temp == 2) ++counter;
        }
        return counter == 1;
    }
};