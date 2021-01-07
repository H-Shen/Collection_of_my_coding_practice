class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for (const char &ch : address) {
            if (ch == '.') {
                s += "[.]";
            } else {
                s.push_back(ch);
            }
        }
        return s;
    }
};