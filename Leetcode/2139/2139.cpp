class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int minSteps = 0;
        if (target == 1) return minSteps;
        while (target != 1) {
            if (!(target & 1)) {
                if (maxDoubles > 0) {
                    target >>= 1;
                    maxDoubles -= 1;
                    minSteps++;
                }
                else {
                    minSteps += (target-1);
                    break;
                }
            }
            else {
                if (maxDoubles > 0) {
                    target -= 1;
                    minSteps++;
                }
                else {
                    minSteps += (target-1);
                    break;
                }
            }
        }
        return minSteps;
    }
};