class Solution {
public:
    string f(const string &S) {
        string s;
        for (const auto &ch : S) {
            if (ch == '#') {
                if (!s.empty()) s.pop_back();
            } else {
                s.push_back(ch);
            }
        }
        return s;
    }
    bool backspaceCompare(string S, string T) {
        return f(S) == f(T);
    }
};