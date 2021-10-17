class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = (int)s.size();
        vector<int> vec;
        string str;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                str.push_back(s[i]);
            }
            else {
                if (!str.empty()) {
                    vec.emplace_back(stoi(str));
                    str.clear();
                }
            }
        }
        if (!str.empty()) {
            vec.emplace_back(stoi(str));
        }
        int length = (int)vec.size();
        if (length <= 1) {
            return true;
        } 
        for (int i = 1; i < length; ++i) {
            if (vec[i-1] >= vec[i]) {
                return false;
            }
        }
        return true;
    }
};