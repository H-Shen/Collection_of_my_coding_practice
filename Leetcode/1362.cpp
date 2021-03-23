class Solution {
public:
    pair<int, int> solve(int n) {
        int temp = sqrt(n * 1.0);
        for (int i = temp; i >= 1; --i) {
            if (n % i == 0) {
                return {i, n / i};
            }
        }
        return {-1, -1};
    }
    vector<int> closestDivisors(int num) {
        auto p1 = solve(num + 1);
        auto p2 = solve(num + 2);
        int dist1 = abs(p1.first - p1.second);
        int dist2 = abs(p2.first - p2.second);
        if (dist1 < dist2) return vector<int>{p1.first, p1.second};
        return vector<int>{p2.first, p2.second};
    }
};