constexpr int MAXN = 26;

class Solution {
public:
    inline bool include(const vector<vector<int>>& vec, const string& s) {
        int currentIndex = -1;
        for (auto& ch : s) {
            auto iter = upper_bound(vec[ch - 'a'].begin(),vec[ch - 'a'].end(), currentIndex);
            if (iter == vec[ch - 'a'].end()) {
                return false;
            }
            currentIndex = *iter;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<vector<int>> vec(MAXN);
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            vec[s[i] - 'a'].emplace_back(i);
        }
        vector<int> result;
        int length = (int)dictionary.size();
        for (int i = 0; i < length; ++i) {
            if (include(vec, dictionary[i])) {
                result.emplace_back(i);
            }
        }
        if (result.empty()) {
            return string();
        }
        return dictionary[*min_element(result.begin(), result.end(), [&](const int &l, const int &r){
            if (dictionary[l].size() == dictionary[r].size()) {
                return dictionary[l] < dictionary[r];
            }
            return dictionary[l].size() > dictionary[r].size();
        })];
    }
};