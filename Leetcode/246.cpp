class Solution {
public:
    bool isStrobogrammatic(string num) {
        for (const auto &ch : num) {
            if (ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '7') {
                return false;
            }
        }
        string numRev(num);
        reverse(numRev.begin(), numRev.end());
        for (auto &ch : numRev) {
            if (ch == '6') {
                ch = '9';
            } else if (ch == '9') {
                ch = '6';
            }
        }
        return numRev == num;
    }
};