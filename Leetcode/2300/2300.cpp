using ll = long long;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int)spells.size();
        int m = (int)potions.size();
        vector<ll> potionsll(m);
        for (int i = 0; i < m; ++i) potionsll[i] = potions[i];
        sort(potionsll.begin(),potionsll.end());
        vector<int> result(n);
        ll temp;
        for (int i = 0; i < n; ++i) {
            temp = success / (ll)spells[i];
            if (success % (ll)spells[i] != 0) ++temp;
            auto iter = lower_bound(potionsll.begin(),potionsll.end(),temp);
            result[i] = (int)(potionsll.end() - iter);
        }
        return result;
    }
};