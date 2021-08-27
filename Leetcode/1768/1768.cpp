class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        auto iter0 = word1.cbegin();
        auto iter1 = word2.cbegin();
        bool flag = true;
        while (true) {
            if (iter0 == word1.cend() && iter1 == word2.cend()) {
                break;
            }
            if (flag) {
                if (iter0 != word1.cend()) {
                    s.push_back(*iter0);
                    ++iter0;
                }
                flag = false;
            }
            else {
                if (iter1 != word2.cend()) {
                    s.push_back(*iter1);
                    ++iter1;
                }
                flag = true;
            }
        }
        return s;
    }
};