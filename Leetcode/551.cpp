class Solution {
public:
    bool checkRecord(string s) {
        return !(count(s.cbegin(), s.cend(), 'A') > 1 || s.find("LLL") != string::npos);
    }
};