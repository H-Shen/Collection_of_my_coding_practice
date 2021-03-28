const regex r("([a-z])\\1*");

class Solution {
public:
    int maxPower(string s) {
        int maxValue = 0;
        for (sregex_iterator a(s.begin(), s.end(), r), e; a != e; ++a) {
            maxValue = max(maxValue, (int)a->str().size());
        }
        return maxValue;
    }
};