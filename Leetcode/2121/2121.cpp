using ll = long long;

constexpr int MAXN = 1e5+5;
ll preLeft[MAXN];
ll preRight[MAXN];

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<ll>> unmap;
        int n = (int)arr.size();
        for (int i = 0; i < n; ++i) {
            unmap[arr[i]].emplace_back(i);
        }
        vector<ll> ans(n);
        for (auto&[k,v] : unmap) {
            ll m = (ll)v.size();
            if (m == 1) {
                ans[v[0]] = 0;
                continue;
            }
            for (ll i = 0; i < m; ++i) {
                if (i == 0) {
                    preLeft[i] = v[i];
                }
                else {
                    preLeft[i] = preLeft[i-1] + v[i];
                }
            }
            for (ll i = m-1; i >= 0; --i) {
                if (i == m-1) {
                    preRight[i] = v[i];
                }
                else {
                    preRight[i] = preRight[i+1] + v[i];
                }
            }
            for (ll i = 0; i < m; ++i) {
                if (i == 0) {
                    ans[v[i]] = preRight[i+1] - (m-1)*v[i];
                }
                else if (i == m-1) {
                    ans[v[i]] = (m-1)*v[i] - preLeft[i-1];
                }
                else {
                    ans[v[i]] = i*v[i] - preLeft[i-1] + preRight[i+1] - (m-(1+i))*v[i];
                }
            }
        }
        return ans;
    }
};