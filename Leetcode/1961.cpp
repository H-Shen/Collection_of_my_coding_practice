class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string str;
        for (const auto &i : words) {
            str += i;
            if (str.size() == s.size()) {
                return str == s;
            }
            else if (str.size() > s.size()) {
                break;
            }
        }
        return false;
    }
};