using ll = long long;

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxDamage = *max_element(damage.begin(),damage.end());
        bool armorNotUsed = true;
        ll sum = 0;
        for (auto&i : damage) {
            sum -= i;
            if (i == maxDamage && armorNotUsed) {
                sum += min(armor, i);
                armorNotUsed = false;
            }
        }
        if (sum >= 0) {
            return 1;
        }
        return -sum+1;
    }
};