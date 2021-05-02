using ll = long long;

class Solution {
public:
    bool check(const string &s, ll n, int& pos) {
        ll target = n - 1;
        if (target == 0) {
            int counter = 0;
            for (size_t i = 0; i != s.size(); ++i) {
                if (s[i] != '0') {
                    break;
                } else {
                    ++counter;
                }
            }
            if (counter == 0) {
                return false;
            }
            pos = counter;
            return true;
        }
        
        for (size_t i = 0; i != s.size(); ++i) {
            try {
                if (stol(s.substr(0, i+1)) == target) {
                    pos = i+1;
                    return true;
                }
            } catch (...) {
                return false;
            }
        }
        return false;
    }
    bool splitString(string s) {
        int k = -1;
        int n = (int)s.size();
        if (n == 1) return false;
        int j;
        string str;
        ll m;
        for (int i = 1; i < n; ++i) {
            try {
                m = stol(s.substr(0, i));
            } catch (...) {
                continue;
            }
            str = s.substr(i);
            while (true) {
                if (check(str, m, j)) {
                    str = str.substr(j);
                    --m;
                    if (str.empty()) {
                        return true;
                    }
                } else {
                    break;
                }
            }
        }
        return false;
    }
};