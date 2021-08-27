class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 0) return 0;
        return (num & 1) ? 1 + numberOfSteps(num - 1) : 1 + numberOfSteps(num >> 1); 
    }
};