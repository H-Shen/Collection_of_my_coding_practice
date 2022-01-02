using ll = long long;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        ll m = mass;
        for (auto&i : asteroids) {
            if (m < i) return false;
            m += i;
        }
        return true;
    }
};