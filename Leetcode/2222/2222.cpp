using ll = long long;

class Solution {
public:
    long long numberOfWays(string s) {
        int n = (int)s.size();
        ll counter = 0;
        // 010
        vector<ll> pre1Left(n);
        if (s[0] == '0') {
            pre1Left[0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                pre1Left[i] = pre1Left[i-1] + 1;
            }
            else {
                pre1Left[i] = pre1Left[i-1];
            }
        }
        vector<ll> pre1Right(n);
        if (s[n-1] == '0') {
            pre1Right[n-1] = 1;
        }
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') {
                pre1Right[i] = pre1Right[i+1] + 1;
            }
            else {
                pre1Right[i] = pre1Right[i+1];
            }
        }
        for (int i = 1; i < n-1; ++i) {
            if (s[i] == '1') {
                counter += pre1Left[i-1]*pre1Right[i+1];
            }
        }
        
        // 101
        vector<ll> pre2Left(n);
        if (s[0] == '1') {
            pre2Left[0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                pre2Left[i] = pre2Left[i-1] + 1;
            }
            else {
                pre2Left[i] = pre2Left[i-1];
            }
        }
        vector<ll> pre2Right(n);
        if (s[n-1] == '1') {
            pre2Right[n-1] = 1;
        }
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '1') {
                pre2Right[i] = pre2Right[i+1] + 1;
            }
            else {
                pre2Right[i] = pre2Right[i+1];
            }
        }
        for (int i = 1; i < n-1; ++i) {
            if (s[i] == '0') {
                counter += pre2Left[i-1]*pre2Right[i+1];
            }
        }
        
        return counter;
    }
};