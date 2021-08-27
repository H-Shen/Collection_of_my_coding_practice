class Solution {
public:
    vector<string> ans;
    bool check(const vector<string> &s) {
        for (const auto &i : s) {
            int temp = stoi(i);
            if (temp > 255) return false;
        }
        return true;
    }
    void dfs(vector<string> vec, const string &s, int i, int n) {
        if (vec.size() == 4) {
            // output
            if (i == n && check(vec)) {
                string ip;
                bool firstItem = true;
                for (const auto &j : vec) {
                    if (firstItem) {
                        firstItem = false;
                    } else {
                        ip.push_back('.');
                    }
                    ip += j;
                }
                ans.emplace_back(ip);
            }
            return;
        }
        string substring;
        for (int index = i; index < n; ++index) {
            substring.push_back(s[index]);
            if (substring.size() > 1 && substring.front() == '0') break;
            if (substring.size() > 3) break;
            vec.emplace_back(substring);
            dfs(vec,s,index+1,n);
            vec.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        decltype(ans)().swap(ans);
        if (s.size() < 4 || s.size() > 3*4) return ans;
        int n = (int)s.size();
        string substring;
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            substring.push_back(s[i]);
            if (substring.size() > 1 && substring.front() == '0') break;
            if (substring.size() > 3) break;
            vec.emplace_back(substring);
            dfs(vec,s,i+1,n);
            vec.pop_back();
        }
        return ans;
    }
};
