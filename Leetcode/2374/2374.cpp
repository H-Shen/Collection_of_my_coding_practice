class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = (int)edges.size();
        vector<long long> in_deg(n);
        for (int i = 0; i < n; ++i) {
            in_deg[edges[i]] += (long long)i;
        }
        return (int)(max_element(in_deg.begin(),in_deg.end()) - in_deg.begin());
    }
};