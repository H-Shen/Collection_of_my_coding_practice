using ll = long long;
constexpr ll MAXN = 26;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = (int)shifts.size();
        vector<ll> totalShifts(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += shifts[i];
        }
        for (int i = 0; i < n; ++i) {
            totalShifts[i] = sum;
            sum -= shifts[i];
        }
        for (int i = 0; i < n; ++i) {
            int moves = (int)(totalShifts[i] % MAXN);
            while (moves > 0) {
                ++S[i];
                if (S[i] > 'z') {
                    S[i] = 'a';
                }
                --moves;
            }
        }
        return S;
    }
};