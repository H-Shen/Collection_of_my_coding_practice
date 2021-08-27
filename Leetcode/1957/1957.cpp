class Solution {
public:
    string makeFancyString(string s) {
        int n = (int)s.size();
        if (n <= 2) {
            return s;
        }
        vector<pair<char,int> > vec;
        int counter = 1;
        char ch = s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == ch) {
                ++counter;
            }
            else {
                vec.emplace_back(ch, counter);
                ch = s[i];
                counter = 1;
            }
        }
        vec.emplace_back(ch, counter);
        string ans;
        for (const auto &[i,j] : vec) {
            if (j > 2) {
                ans.push_back(i);
                ans.push_back(i);
            }
            else {
                for (int k = 0; k < j; ++k) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};