class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log(num) / log(4.0), 1) == 0.0;
    }
};