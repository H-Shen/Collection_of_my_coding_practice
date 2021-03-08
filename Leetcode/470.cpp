// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // Reject Sampling
        int a = 7*(rand7()-1)+rand7();
        if (a > 40) return rand10();
        int result = a % 10;
        return (result == 0) ? 10 : result;
    }
};