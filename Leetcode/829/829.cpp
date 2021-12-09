class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int a = 2*n;
        int upper = sqrt(a*1.0);
        int counter = 0;
        int x,y;
        // a+b=x
        // b-a+1=y
        for (int i = upper; i >= 1; --i) {
            if (a % i == 0) {
                x = i;
                y = a / i;
                if (x < y) swap(x,y);
                if (!((x + y - 1) & 1)) ++counter;
            }
        }
        return counter;
    }
};