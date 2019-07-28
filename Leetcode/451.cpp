class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const auto &p : s) {
            ++freq[p];
        }
        vector<pair<char, int> > A(freq.size());
        auto it = freq.cbegin();
        for (auto &p : A) {
            p = (*it);
            ++it;
        }
        sort(A.begin(), A.end(), [](const pair<char, int> &a, const pair<char, int> &b) -> bool {
            return (a.second > b.second);
        });
        string res;
        for (const auto &it0 : A) {
            string tmp(static_cast<unsigned long>(it0.second), it0.first);
            res += tmp;
        }
        return res;
    }
};