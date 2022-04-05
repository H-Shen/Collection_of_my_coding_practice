class Solution {
public:
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        return (f(n-1,m) + m) % n;
    }
    int findTheWinner(int n, int k) {
        return f(n,k)+1;
    }
};