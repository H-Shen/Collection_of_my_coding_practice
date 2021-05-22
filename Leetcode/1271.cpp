class Solution {
public:
    string toHexspeak(string num) {
        using ll = long long;
        ll temp;
        try {
            temp = stoll(num);
        } catch (...) {
            return "ERROR";
        }
        constexpr int LENGTH = 20;
        char hexVal[LENGTH];
        sprintf(hexVal, "%llx", temp);  // long long hex
        string hex(hexVal);
        for (auto &ch : hex) {
            if (ch == '0') {
                ch = 'O';
            }
            else if (ch == '1') {
                ch = 'I';
            }
            ch = toupper(ch);
            if (ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F' && ch != 'I' && ch != 'O') {
                return "ERROR";
            }
        }
        return hex;
    }
};