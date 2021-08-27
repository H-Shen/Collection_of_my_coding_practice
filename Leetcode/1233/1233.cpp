const char SEPARATOR = '/';

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> unset(folder.begin(),folder.end());
        unordered_set<string> shouldRemove;
        string str;
        for (const auto &i : folder) {
            str = i;
            while (true) {
                while (str.back() != SEPARATOR) {
                    str.pop_back();
                }
                str.pop_back();
                if (str.empty()) break;
                if (unset.find(str) != unset.end()) {
                    shouldRemove.insert(i);
                    break;
                }
            }
        }
        vector<string> ans;
        for (const auto &i : folder) {
            if (shouldRemove.find(i) == shouldRemove.end()) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};