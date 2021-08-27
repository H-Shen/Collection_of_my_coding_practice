class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = target[0];
        int b = target[1];
        int c = target[2];
        int n = (int)triplets.size();
        // Condition 1:
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (triplets[i][0] == a && triplets[i][1] <= b && triplets[i][2] <= c) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
        // Condition 2:
        flag = false;
        for (int i = 0; i < n; ++i) {
            if (triplets[i][0] <= a && triplets[i][1] == b && triplets[i][2] <= c) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
        // Condition 3:
        flag = false;
        for (int i = 0; i < n; ++i) {
            if (triplets[i][0] <= a && triplets[i][1] <= b && triplets[i][2] == c) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
        return true;
    }
};