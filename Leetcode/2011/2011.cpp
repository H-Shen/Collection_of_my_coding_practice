class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto &i : operations) {
            if (i[0] == '-' || i[2] == '-') {
                --x;
            } else {
                ++x;
            }
        }
        return x;
    }
};