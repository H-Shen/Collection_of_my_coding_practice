constexpr int N = 20;
vector<int> v;

class Solution {
public:
    int minOperations(int n) {
        if (v.empty()) {
            v.emplace_back(1);
            while ((int)v.size() < N) {
                v.emplace_back(v.back() * 2);
            }
        }
        int ans = 0;
        int pos, l, r, dist_l, dist_r;
        while (n != 0) {
            if (binary_search(v.begin(),v.end(),n)) {
                ++ans;
                n = 0;
                continue;
            }
            pos = (int)(lower_bound(v.begin(),v.end(),n) - v.begin());
            l = v[pos-1];
            r = v[pos];
            dist_l = abs(n - l);
            dist_r = abs(n - r);
            if (dist_l < dist_r) {
                n = dist_l;
            }
            else {
                n = dist_r;
            }
            ++ans;
        }

        return ans;
    }
};