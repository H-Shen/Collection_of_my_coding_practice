class Solution {
public:
    string removeDuplicates(string S) {
        list<char> l(S.begin(), S.end());
        bool checkAgain;
        while (l.size() > 1) {
            checkAgain = false;
            for (auto iter = l.begin(); iter != l.end(); ++iter) {
                if (iter != l.begin()) {
                    auto iter1 = iter;
                    --iter1;
                    if (*iter == *iter1) {
                        l.erase(iter);
                        l.erase(iter1);
                        checkAgain = true;
                        break;
                    }
                }
            }
            if (!checkAgain) break;
        }
        return string(l.begin(), l.end());
    }
};