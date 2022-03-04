constexpr int MAXN = 1e5+5;

int left_b[MAXN];
int right_a[MAXN];

class Solution {
public:
    int minimumDeletions(string s) {
        int n = (int)s.size();
        if (n <= 1) return 0;
        if (s[0] == 'b') {
            left_b[0] = 1;
        }
        else {
            left_b[0] = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'b') {
                left_b[i] = left_b[i-1] + 1;
            }
            else {
                left_b[i] = left_b[i-1];
            }
        }
        if (s[n-1] == 'a') {
            right_a[n-1] = 1;
        }
        else {
            right_a[n-1] = 0;
        }
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == 'a') {
                right_a[i] = right_a[i+1] + 1;
            }
            else {
                right_a[i] = right_a[i+1];
            }
        }
        int minVal = numeric_limits<int>::max();
        minVal = min({minVal, right_a[1], left_b[n-2]});
        for (int i = 1; i < n-1; ++i) {
            minVal = min(minVal, left_b[i-1] + right_a[i+1]);
        }
        return minVal;
    }
};