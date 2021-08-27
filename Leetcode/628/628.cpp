class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxVal = numeric_limits<int>::min();
        vector<int> positive, negative;
        bool containsZero = false;
        for (const auto &i : nums) {
            if (i == 0) {
                containsZero = true;
            }
            else if (i > 0) {
                positive.emplace_back(i);
            }
            else {
                negative.emplace_back(i);
            }
        }
        sort(positive.begin(),positive.end());
        sort(negative.begin(),negative.end());
        int temp;
        // positive: p negative: n
        // p p p
        if (positive.size() >= 3) {
            temp = positive[positive.size()-1]*positive[positive.size()-2]*positive[positive.size()-3];
            maxVal = max(maxVal, temp);
        }
        // n n n
        if (negative.size() >= 3) {
            temp = negative[negative.size()-1]*negative[negative.size()-2]*negative[negative.size()-3];
            maxVal = max(maxVal, temp);
        }
        // p p n
        if (positive.size() >= 2 && negative.size() >= 1) {
            temp = positive[0]*positive[1]*negative[negative.size()-1];
            maxVal = max(maxVal, temp);
        }
        // n n p
        if (positive.size() >= 1 && negative.size() >= 2) {
            temp = negative[0]*negative[1]*positive[positive.size()-1];
            maxVal = max(maxVal, temp);
        }
        // 0
        if (containsZero) {
            maxVal = max(maxVal, 0);
        }
        return maxVal;
    }
};