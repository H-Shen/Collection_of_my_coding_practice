class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int s1 = 0, s2 = 0;
        for (const auto &ch : moves) {
            if (ch == '_' || ch == 'L') ++s1;
            else --s1;
        }
        for (const auto &ch : moves) {
            if (ch == '_' || ch == 'R') ++s2;
            else --s2;
        }
        return max(abs(s1), abs(s2));
    }
};