template<class T>
bool kmp(T const &Text, T const &Pattern) {
    vector<int> b(Pattern.size() + 1, -1);
    // Preprocess
    for (size_t i = 1; i <= Pattern.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && Pattern[pos] != Pattern[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }
    // Search
    int sp = 0, kp = 0;
    while (sp < Text.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != Text[sp])) {
            kp = b[kp];
        }
        ++kp;
        ++sp;
        if (kp == Pattern.size()) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s = word;
        int counter = 0;
        do {
            if (!kmp(sequence, s)) {
                break;
            }
            ++counter;
            s += word;
        } while (true);
        return counter;
    }
};