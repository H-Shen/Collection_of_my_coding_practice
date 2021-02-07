class Solution {
public:
    vector<string> split(const string &A) {
        vector<string> result;
        istringstream iss(A);
        string s;
        do {
            iss >> s;
            result.emplace_back(s);
        } while (iss);
        result.pop_back();
        return result;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        auto a = split(A);
        auto b = split(B);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<string> v;
        set_symmetric_difference(
        a.begin(), a.end(),
        b.begin(), b.end(),
        back_inserter(v));
        unordered_set<string> unset(v.begin(), v.end());
        unordered_map<string, int> freq_a;
        for (const auto &i : a) ++freq_a[i];
        unordered_map<string, int> freq_b;
        for (const auto &i : b) ++freq_b[i];
        for (const auto &i : a) if (freq_a[i] > 1) unset.erase(i);
        for (const auto &i : b) if (freq_b[i] > 1) unset.erase(i);
        vector<string> result;
        for (const auto &i : unset) result.emplace_back(i);
        return result;
    }
};