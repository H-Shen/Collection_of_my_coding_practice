using ll = long long;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for (auto& i : roads) {
            ++deg[i[0]];
            ++deg[i[1]];
        }
        vector<int> nodes(n);
        iota(nodes.begin(),nodes.end(),0);
        sort(nodes.begin(),nodes.end(),[&](const auto &l, const auto &r){
            return deg[l] > deg[r];
        });
        vector<int> weight(n);
        for (int i = 0, j = n; i < n; ++i, --j) {
            weight[nodes[i]] = j;
        }
        ll sum = 0;
        for (auto& i : roads) {
            sum += weight[i[0]];
            sum += weight[i[1]];
        }
        return sum;
    }
};