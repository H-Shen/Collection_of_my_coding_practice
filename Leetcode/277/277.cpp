/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    // 2*n calls
    bool check(int i, int n) const {
        for (int j = 0; j <= n-1; ++j) {
            if (i == j) {
                continue;
            }
            if (knows(i,j) || !knows(j,i)) {
                return false;
            }
        }
        return true;
    }
    int findCelebrity(int n) {
        vector<int> vec;
        for (int i = 0; i <= n-1; ++i) {
            vec.emplace_back(i);
        }
        int ans;
        int a, b;
        // n calls
        while (true) {
            if (vec.empty()) {
                ans = -1;
                break;
            }
            else if (vec.size() == 1) {
                ans = (check(vec.back(),n) ? vec.back() : -1);
                break;
            }
            else {
                a = vec.back();
                vec.pop_back();
                b = vec.back();
                vec.pop_back();
                if (knows(a, b)) {
                    vec.emplace_back(b);
                }
                else {
                    vec.emplace_back(a);
                }
            }
        }
        return ans;
    }
};