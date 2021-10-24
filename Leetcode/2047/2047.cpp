bool check(const string &s) {
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !isdigit(s[i]) && s[i] != '-' && s[i] != '!' && s[i] != '.' && s[i] != ',') {
            return false;
        }
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            return false;
        }
        else if (s[i] == '-') {
            ++c1;
        }
        else if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
            ++c2;
        }
    }
    if (c1 > 1 || c2 > 1) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '-') {
            if (i == 0 || i == n-1) {
                return false;
            }
            else if (!islower(s[i-1]) || !islower(s[i+1])) {
                return false;
            }
        }
        if ((s[i] == '!' || s[i] == '.' || s[i] == ',') && i != n-1) {
            return false;
        }
    }
    return true;
}
class Solution {
public:
    int countValidWords(string s) {
        int n = (int)s.size();
        string str;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    if (check(str)) {
                        ++counter;
                    }
                    str.clear();
                }
            }
            else {
                str.push_back(s[i]);
            }
        }
        if (!str.empty()) {
            if (check(str)) {
                ++counter;
            }
        }
        return counter;
    }
};