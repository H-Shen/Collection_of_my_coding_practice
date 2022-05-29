constexpr int MAXN = 40;

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

inline static
bool check(const string &s, double &val) {
    if (s.empty()) {
        return false;
    }
    if (s[0] != '$') {
        return false;
    }
    int counter = 0;
    for (size_t i = 1; i != s.size(); ++i) {
        if (!isdigit(s[i])) {
            if (s[i] == '.') {
                ++counter;
                if (counter > 1) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    try {
        val = stod(s.substr(1));
    } catch (...) {
        return false;
    }
    return true;
}

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> vec = splitByChar(sentence, ' ');
        double d;
        for (auto&i : vec) {
            if (check(i, d)) {
                char output[MAXN]{};
                snprintf(output, MAXN, "%.2lf", d * (100-discount) / 100.0);
                i = string("$") + output;
            }
        }
        bool firstItem = true;
        string ans;
        for (auto&i : vec) {
            if (firstItem) {
                firstItem = false;
            }
            else {
                ans.push_back(' ');
            }
            ans += i;
        }
        return ans;
    }
};