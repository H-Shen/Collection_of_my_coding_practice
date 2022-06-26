class Solution {
public:
    int countAsterisks(string s) {
        int n = (int)s.size();
        string str;
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '|') {
                str.push_back(s[i]);
            }
            else {
                vec.emplace_back(str);
                str.clear();
            }
        }
        if (!str.empty()) {
            vec.emplace_back(str);
        }
        int cnt = 0;
        int length = (int)vec.size();
        for (int i = 0; i < length; ++i) {
            if (!(i & 1)) {
                cnt += (int)count(vec[i].begin(),vec[i].end(),'*');
            }
        }
        return cnt;
    }
};