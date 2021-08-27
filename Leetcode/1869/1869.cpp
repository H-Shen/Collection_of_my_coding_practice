class Solution {
public:
    bool checkZeroOnes(string s) {
        vector<pair<char,int> > v;
        int n = (int)s.size();
        char last;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                last = s[i];
                counter = 1;
                continue;
            }
            if (s[i] == last) {
                ++counter;
            }
            else {
                v.emplace_back(last, counter);
                last = s[i];
                counter = 1;
            }
        }
        v.emplace_back(last, counter);
        int maxOne = 0;
        int maxZero = 0;
        for (const auto &[i,j] : v) {
            if (i == '0') {
                maxZero = max(maxZero, j);
            }
            else if (i == '1') {
                maxOne = max(maxOne, j);
            }
        }
        return maxOne > maxZero;
    }
};