class Solution {
public:
    string sortVowels(string s) {
        string str;
        char temp;
        for (const char &ch : s) {
            temp = tolower(ch);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') str.push_back(ch);
        }
        sort(str.begin(),str.end());
        auto iter = str.begin();
        for (char &ch : s) {
            temp = tolower(ch);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
                ch = *iter;
                ++iter;
            }
        }
        return s;
    }
};