class Solution {
public:
    vector<string> split(const string &text) {
        vector<string> split;
        string s;
        for (const char &ch : text) {
            if (ch == ' ') {
                if (!s.empty()) {
                    split.emplace_back(s);
                    s.clear();
                }
            } else {
                s.push_back(ch);
            }
        }
        if (!s.empty()) {
            split.emplace_back(s);
        }
        return split;
    }
    vector<string> findOcurrences(string text, string first, string second) {
        auto p = split(text);
        vector<string> output;
        if (p.size() <= 2) return output;
        int n = (int)p.size();
        for (int i = 0; i < n - 2; ++i) {
            if (p.at(i) == first && p.at(i + 1) == second) {
                output.emplace_back(p.at(i + 2));
            }
        }
        return output;
    }
};