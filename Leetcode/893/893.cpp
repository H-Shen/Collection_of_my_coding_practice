class Solution {
public:
    string f(const string &s) {
        deque<char> odd, even;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                odd.emplace_back(s.at(i));
            } else {
                even.emplace_back(s.at(i));
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        string result;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                result.push_back(odd.front());
                odd.pop_front();
            } else {
                result.push_back(even.front());
                even.pop_front();
            }
        }
        return result;
    }
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> unset;
        for (const auto &i : A) unset.insert(f(i));
        return (int)unset.size();
    }
};