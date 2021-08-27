class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > A;
        string tmp;
        for (const auto &i : strs) {
            tmp = i;
            sort(tmp.begin(), tmp.end());
            A[tmp].push_back(i);
        }
        vector<vector<string>> res;
        for (const auto &it : A) {
            res.push_back(it.second);
        }
        return res;
    }
};