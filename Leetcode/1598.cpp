class Solution {
public:
    int minOperations(vector<string>& logs) {
        int height = 0;
        for (const auto &i : logs) {
            if (i == "./") {
                continue;
            }
            else if (i == "../") {
                if (height > 0) {
                    --height;
                }
            }
            else {
                ++height;
            }
        }
        return height;
    }
};