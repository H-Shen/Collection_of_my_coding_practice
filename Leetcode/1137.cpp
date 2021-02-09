class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        vector<int> A = {0, 1, 1};
        for (int i = 2; i < n; ++i) {
            int temp = A[0] + A[1] + A[2];
            swap(A[0], A[1]);
            swap(A[1], A[2]);
            A[2] = temp;
        }
        return A[2];
    }
};