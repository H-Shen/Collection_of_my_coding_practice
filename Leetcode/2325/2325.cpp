class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> unmap;
        char ch = 'a';
        for (const char &i : key) {
            if (isalpha(i)) {
                if (unmap.count(i) == 0) {
                    unmap[i] = ch;
                    ++ch;
                }
            }
        }
        string result;
        for (const char &i : message) {
            if (unmap.count(i) > 0) {
                result.push_back(unmap[i]);
            }
            else {
                result.push_back(' ');
            }
        }
        return result;
    }
};