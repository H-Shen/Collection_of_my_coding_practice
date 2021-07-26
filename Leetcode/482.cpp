class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;
        for (const auto &ch : s) {
            if (ch != '-') str.push_back(toupper(ch));
        }
        vector<string> v;
        int counter = 0;
        string temp;
        for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
            temp.push_back(*iter);
            ++counter;
            if (counter == k) {
                reverse(temp.begin(),temp.end());
                v.emplace_back(temp);
                counter = 0;
                temp.clear();
            }
        }
        if (counter > 0) {
            reverse(temp.begin(),temp.end());
            v.emplace_back(temp);
        }
        string ans;
        bool firstItem = true;
        for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
            if (firstItem) {
                firstItem = false;
            } else {
                ans.push_back('-');
            }
            ans += *iter;
        }
        return ans;
    }
};