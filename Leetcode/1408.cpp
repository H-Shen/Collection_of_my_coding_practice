template<class T>
bool KMP(T const& String, T const& Pattern) {
    vector<int> b(Pattern.size() + 1, -1);
    vector<int> matches;
    // Preprocess
    for (size_t i = 1; i <= Pattern.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && Pattern[pos] != Pattern[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }
    // Search
    int sp = 0, kp = 0;
    while (sp < String.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != String[sp])) kp = b[kp];
        kp++; sp++;
        if (kp == Pattern.size()) return true;
    }
    return false;
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> answer;
        int n = (int)words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && KMP(words.at(j), words.at(i))) {
                    answer.insert(words.at(i));
                }
            }
        }
        return vector<string>(answer.begin(), answer.end());
    }
};