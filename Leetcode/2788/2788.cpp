class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        auto f = [&](const string &s) {
            vector<string> vec;
            string temp;
            for (const char& ch : s) {
                if (ch == separator) {
                    if (!temp.empty()) {
                        vec.emplace_back(temp);
                        temp.clear();
                    }
                }
                else {
                    temp.push_back(ch);
                }
            }
            if (!temp.empty()) {
                vec.emplace_back(temp);
            }
            return vec;
        };
        for (const string& word : words) {
            vector<string> p = f(word);
            for (const string& str : p) {
                ans.emplace_back(str);
            }
        }
        return ans;
    }
};