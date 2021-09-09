class Solution {
public:
    bool check(const string &l, const string &r) {
        string lastWord;
        for (auto iter = l.crbegin(); iter != l.crend(); ++iter) {
            if (*iter == ' ') {
                break;
            }
            lastWord.push_back(*iter);
        }
        reverse(lastWord.begin(),lastWord.end());
        string firstWord;
        for (auto iter = r.cbegin(); iter != r.cend(); ++iter) {
            if (*iter == ' ') {
                break;
            }
            firstWord.push_back(*iter);
        }
        return firstWord == lastWord;
    }
    string merge(const string &l, const string &r) {
        string s = l;
        auto iter = r.cbegin();
        for (; iter != r.cend(); ++iter) {
            if (*iter == ' ') {
                break;
            }
        }
        for (; iter != r.cend(); ++iter) {
            s.push_back(*iter);
        }
        return s;
    }
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_set<string> unset;
        int n = (int)phrases.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && check(phrases[i],phrases[j])) {
                    unset.insert(merge(phrases[i], phrases[j]));
                }
            }
        }
        vector<string> ans(unset.begin(),unset.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};