class Solution {
public:
    int maxNumberOfBalloons(string text) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const auto &i : text) ++stats[i-'a'];
        int counter = 0;
        while (true) {
            if (stats['b'-'a'] > 0) {
                --stats['b'-'a'];
            } else {
                break;
            }
            if (stats['a'-'a'] > 0) {
                --stats['a'-'a'];
            } else {
                break;
            }
            if (stats['l'-'a'] > 1) {
                stats['l'-'a'] -= 2;
            } else {
                break;
            }
            if (stats['o'-'a'] > 1) {
                stats['o'-'a'] -= 2;
            } else {
                break;
            }
            if (stats['n'-'a'] > 0) {
                --stats['n'-'a'];
            } else {
                break;
            }
            ++counter;
        }
        return counter;
    }
};