class Solution {
public:
    int minFlips(string s) {
        int n = (int)s.size();
        vector<int> A(n+1);
        vector<int> B(n+1);
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (s[i] == '1') {
                    A.at(i+1) = A.at(i) + 1;
                    B.at(i+1) = B.at(i);
                } else {
                    A.at(i+1) = A.at(i);
                    B.at(i+1) = B.at(i) + 1;
                }
            }
            else {
                if (s[i] == '1') {
                    A.at(i+1) = A.at(i);
                    B.at(i+1) = B.at(i) + 1;
                } else {
                    A.at(i+1) = A.at(i) + 1;
                    B.at(i+1) = B.at(i);
                }
            }
        }
        int ans = min(A.at(n),B.at(n));
        if (n & 1) {
            for (int i = 0; i < n; ++i) {
                ans = min(ans, min(A.at(n)-A.at(i+1)+B.at(i+1), B.at(n)-B.at(i+1)+A.at(i+1)));
            }
        }
        return ans;
    }
};