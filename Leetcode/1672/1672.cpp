class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = (int)accounts.size();
        int n = accounts.front().size();
        vector<int> clients(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                clients.at(i) += accounts.at(i).at(j);
            }
        }
        return *max_element(clients.begin(), clients.end());
    }
};