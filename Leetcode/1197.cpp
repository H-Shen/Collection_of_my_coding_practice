class Solution {
public:
    int minKnightMoves(int x, int y) {
        // https://open.kattis.com/problems/knightstrip
        x = abs(x);
        y = abs(y);
        if (x > y) {
            swap(x,y);
        }
        int steps, extra_steps;
        if (y <= 2*x) {
            if (x == 2 && y == 2) {
                steps = 4;
            } else {
                steps = (x+y)/3 + (x+y)%3;
            }
        } else {
            if (x == 0 && y == 1) {
                steps = 3;
            } else {
                steps = x;
                extra_steps = (y-2*x)%4;
                steps += extra_steps;
                steps += (y-2*x-extra_steps)/2;
            }
        }
        return steps;
    }
};