class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> adder(digits.size(), 0);
        adder.at(0) = 1;
        vector<int> result(digits.size() + 1, 0);
        int n = (int)digits.size();
        for (int i = 0; i < n; ++i) {
            result.at(i) += adder.at(i) + digits.at(i);   
            if (result.at(i) >= 10) {
                result.at(i) -= 10;
                ++result.at(i + 1);
            }
        }
        if (result.back() == 0) {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};