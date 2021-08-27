class Solution {
public:
    string join(const vector<string> &v) {
        string s;
        for (const auto &i : v) s += i;
        return s;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return join(word1) == join(word2);
    }
};