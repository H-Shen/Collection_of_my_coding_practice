using ll = long long;

constexpr int MAXN = 100;
constexpr ll MOD = 1e9+7;
ll freq[MAXN+5];
bool vis[MAXN+5][MAXN+5][MAXN+5];   // store unique and sorted triplets
int t;

class Solution {
public:
    ll cnt(int x, int y, int z) {
        if (x == y && y == z) {
            return freq[x]*(freq[x]-1)*(freq[x]-2)/6;
        }
        else if (x != y && y != z && x != z) {
            return freq[x]*freq[y]*freq[z];
        }
        else if (x == y && y != z) {
            return freq[x]*(freq[x]-1)/2*freq[z];
        }
        else if (x == z && y != z) {
            return freq[x]*(freq[x]-1)/2*freq[y];
        }
        return freq[y]*(freq[y]-1)/2*freq[x];
    }
    int threeSumMulti(vector<int>& arr, int target) {
        memset(vis, 0, sizeof vis);
        int n = (int)arr.size();
        memset(freq, 0, sizeof freq);
        for (int i = 0; i < n; ++i) {
            ++freq[arr[i]];
        }
        t = target;
        ll counter = 0;
        int vec[3];
        for (int x = 0; x <= MAXN; ++x) {
            for (int y = 0; y <= MAXN; ++y) {
                int z = target-x-y;
                if (z >= 0 && z <= MAXN && freq[x] > 0 && freq[y] > 0 && freq[z] > 0) {
                    vec[0] = x; vec[1] = y; vec[2] = z;
                    sort(vec, vec+3);
                    if (!vis[vec[0]][vec[1]][vec[2]]) {
                        vis[vec[0]][vec[1]][vec[2]] = true;
                        counter = (counter + cnt(vec[0],vec[1],vec[2])) % MOD;
                    }
                }
            }
        }
        return (int)(counter % MOD);
    }
};