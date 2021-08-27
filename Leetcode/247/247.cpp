const vector<char> v1 = {'1','6','9','8'};
const vector<char> v2 = {'1','6','9','8','0'};
const vector<char> v3 = {'0','1','8'};

class Solution {
public:
    vector<string> ans;
    void f(int len, int n, string s) {
        if (len == n) {
            ans.emplace_back(s);
            return;
        }
        if (len == 0) {
            for (const char &i : v1) {
                s.push_back(i);
                f(1, n, s);
                s.pop_back();
            }
        }
        else {
            if (n & 1) {
                if (len < n / 2) {
                    for (const char &i : v2) {
                        s.push_back(i);
                        f(len+1,n,s);
                        s.pop_back();
                    }
                }
                else {
                    for (const char &i : v3) {
                        s.push_back(i);
                        for (int j = n/2-1; j >= 0; --j) {
                            if (s[j] == '0' || s[j] == '1' || s[j] == '8') {
                                s.push_back(s[j]);
                            }
                            else if (s[j] == '6') {
                                s.push_back('9');
                            }
                            else {
                                s.push_back('6');
                            }
                        }
                        f(n,n,s);
                        while ((int)s.size() > len) {
                            s.pop_back();
                        }
                    }
                }
            }
            else {
                if (len < n / 2) {
                    for (const char &i : v2) {
                        s.push_back(i);
                        f(len+1, n, s);
                        s.pop_back();
                    }
                }
                else {
                    for (int i = n/2-1; i >= 0; --i) {
                        if (s[i] == '0' || s[i] == '1' || s[i] == '8') {
                            s.push_back(s[i]);
                        }
                        else if (s[i] == '6') {
                            s.push_back('9');
                        }
                        else {
                            s.push_back('6');
                        }
                    }
                    f(n,n,s);
                }
            }
        }
    }
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) {
            return {"0","1","8"};
        }
        else if (n == 2) {
            return {"11","69","88","96"};
        }
        vector<string>().swap(ans);
        f(0, n, string());
        return ans;
    }
};