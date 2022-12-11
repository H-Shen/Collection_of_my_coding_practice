class Solution {
public:
    inline
    bool digitsOnly(const string& s) const {
        for (const auto&ch : s) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for (auto&i : strs) {
            if (digitsOnly(i)) {
                maxVal = max(maxVal, stoi(i));
            } else {
                maxVal = max(maxVal, (int)i.size());
            }
        }
        return maxVal;
    }
};