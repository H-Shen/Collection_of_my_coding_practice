using ll = long long;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<ll> positive, zero, negative;
        for (auto&i : nums) {
            if (i > 0) positive.emplace_back(i);
            else if (i == 0) zero.emplace_back(i);
            else negative.emplace_back(i);
        }
        sort(negative.begin(),negative.end());
        int len0 = (int)positive.size();
        int len1 = (int)negative.size();
        int len2 = (int)zero.size();
        if (len0 == 0 && len1 == 0 && len2 > 0) {
            return 0;
        }
        else if (len0 == 0 && len1 > 0 && len2 == 0) {
            if (len1 == 1) {
                return negative[0];
            }
            else if (len1 & 1) {
                negative.pop_back();
            }
            ll result = 1;
            for (auto&i : negative) result *= i;
            return result;
        }
        else if (len0 == 0 && len1 > 0 && len2 > 0) {
            if (len1 == 1) {
                return 0;
            }
            else if (len1 & 1) {
                negative.pop_back();
            }
            ll result = 1;
            for (auto&i : negative) result *= i;
            return result;
        }
        else {
            ll result = 1;
            for (auto&i : positive) result *= i;
            if (len1 > 1) {
                if (len1 & 1) {
                    negative.pop_back();
                }
                for (auto&i : negative) result *= i;
            }
            return result;
        }
    }
};