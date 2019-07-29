class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        using ll = long long;
        constexpr int maxn = 90;
        vector <ll> A;
        A.push_back(1);
        A.push_back(2);
        while (A.size() <= maxn) {
            int n = A.size();
            A.push_back(A[n - 1] + A[n - 2]);
        }
        return static_cast<int>(A[n - 1]);
    }
};