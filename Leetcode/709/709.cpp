class Solution {
public:
    string toLowerCase(string str) {
        for (char &ch : str) {
            if (isupper(ch)) {
                ch = tolower(ch);
            }
        }
        return str;
    }
};