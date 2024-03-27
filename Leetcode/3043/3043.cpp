class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> unset;
        string s;
        for (const auto &i : arr1) {
            s = to_string(i);
            while (!s.empty()) {
                unset.insert(s);
                s.pop_back();
            }
        }
        int ans = 0;
        for (const auto &i : arr2) {
            s = to_string(i);
            while (true) {
                if ((int)s.size() <= ans) break;
                if (unset.count(s) > 0) {
                    ans = (int)s.size();
                    break;
                }
                else {
                    s.pop_back();
                }
            }
        }
        return ans;
    }
};