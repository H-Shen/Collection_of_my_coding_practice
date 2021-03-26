class Solution {
public:
    string f(const string &s) {
        string localName;
        for (int i = 0; s[i] != '@'; ++i) {
            if (s[i] != '.') {
                if (s[i] == '+') break;
                else localName.push_back(s[i]);
            }
        }
        return localName + s.substr(s.find('@'));
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unset;
        for (const auto &i : emails) {
            unset.insert(f(i));
        }
        return unset.size();
    }
};