class Solution {
public:
    long long smallestNumber(long long num) {
        if (num < 0) {
            string s = to_string(num);
            vector<char> v1, v2;
            for (auto &ch : s) {
                if (ch == '-') continue;
                if (ch == '0') v2.emplace_back(ch);
                else v1.emplace_back(ch);
            }
            sort(v1.begin(),v1.end(),greater<>());
            string ans;
            ans.push_back('-');
            for (auto& ch : v1) {
                ans.push_back(ch);
            }
            for (auto& ch : v2) {
                ans.push_back(ch);
            }
            return stoll(ans);
        }
        else {
            string s = to_string(num);
            vector<char> v1, v2;
            for (auto &ch : s) {
                if (ch == '0') v2.emplace_back(ch);
                else v1.emplace_back(ch);
            }
            string ans;
            sort(v1.begin(),v1.end());
            if (v2.empty()) {
                for (auto &ch : v1) {
                    ans.push_back(ch);
                }
            }
            else if (v1.empty()) {
                for (auto &ch : v2) {
                    ans.push_back(ch);
                } 
            }
            else {
                ans.push_back(v1[0]);
                for (auto &ch : v2) {
                    ans.push_back(ch);
                }
                for (int i = 1; i < (int)v1.size(); ++i) {
                    ans.push_back(v1[i]);
                }
            }
            return stoll(ans);
        }
    }
};