constexpr int MAXN = 1e7+5;
vector<int> power;
bool haveAns;
int m;

class Solution {
public:
    void dfs(int val, int i) {
        if (haveAns) return;
        val -= power[i];
        if (val == 0) {
            haveAns = true;
            return;
        }
        for (int j = i+1; j < m; ++j) {
            if (power[j] > val) {
                break;
            }
            dfs(val, j);
        }
    }
    bool checkPowersOfThree(int n) {
        power.emplace_back(1);
        while (power.back() < MAXN) {
            power.emplace_back(power.back() * 3);
        }
        haveAns = false;
        m = (int)power.size();
        for (int i = 0; i < m; ++i) {
            if (haveAns) break;
            if (power[i] > n) break;
            dfs(n, i);
        }
        return haveAns;
    }
};