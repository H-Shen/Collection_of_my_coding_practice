using ll = long long;

class Solution {
public:
    int kthGrammar(int n, int k) {
        ll index = (1LL<<(n-1))-1LL+(ll)k;
        string s;
        while (true) {
            if (index == 1) break;
            if (index & 1) {
                s.push_back('R');
            }
            else {
                s.push_back('L');
            }
            index >>= 1;
        }
        int ans = 0;
        for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
            if (*iter == 'R') {
                ans = (ans == 0) ? 1 : 0;
            }
        }
        return ans;
    }
};