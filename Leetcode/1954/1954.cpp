using ll = long long;
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll counter = 0;
        for (ll k = 1;; ++k) {
            counter += 12LL*k*k;
            if (counter >= neededApples) {
                return 8*k;
            }
        }
        return -1;
    }
};