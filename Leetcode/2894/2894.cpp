class Solution {
public:
    int differenceOfSums(int n, int m) {
        // s = (1+n)*n/2
        // num2 = (m+k*m)*k/2=m*(1+k)*k/2
        // num1 = s - num2
        // k = n / m
        int s = ((1+n)*n)>>1;
        if (n < m) {
            return s;
        }
        int k = n / m;
        int num2 = m*(((1+k)*k)>>1);
        int num1 = s - num2;
        return num1 - num2;
    }
};