class Solution {
public:
    int minFlips(string target) {
        int n = (int)target.size();
        int counter = 0;
        bool flip = false;
        for (int i = 0; i < n; ++i) {
            if (target[i] == '1') {
                if (flip) {
                    continue;
                }
                else {
                    flip = true;
                    ++counter;
                }
            }
            else {
                if (flip) {
                    flip = false;
                    ++counter;
                }
                else {
                    continue;
                }
            }
        }
        return counter;
    }
};