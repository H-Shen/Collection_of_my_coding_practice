class Solution {
public:
    double f(double x, long long n) {
        if (x == 1.0) return 1.0;
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n < 0) return 1.0 / f(x,-n);
        double temp = f(x, n/2);
        return (n % 2 == 0) ? temp*temp : temp*temp*x; 
    }
    double myPow(double x, int n) {
        return f(x,n);
    }
};