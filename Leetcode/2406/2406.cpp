constexpr int MAXN = 1e6+5;

int A[MAXN];

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        memset(A, 0, sizeof A);
        int l, r;
        for (auto&i : intervals) {
            l = i[0];
            r = i[1];
            ++A[l];
            --A[r+1];
        }
        for (int i = 1; i < MAXN; ++i) {
            A[i] += A[i-1];
        }
        return *max_element(A, A+MAXN);
    }
};