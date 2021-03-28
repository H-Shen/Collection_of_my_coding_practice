const regex r("[0-9]+");

class Solution {
public:
    string removeRedundantHeadingZeroes(const string &s) {
        deque<char> dq(s.begin(), s.end());
        while (dq.size() >= 2 && dq.front() == '0') {
            dq.pop_front();
        }
        return string(dq.begin(), dq.end());
    }
    int numDifferentIntegers(string word) {
        unordered_set<string> unset;
        for (sregex_iterator it(word.begin(), word.end(), r), end_it; it != end_it; ++it) {
            unset.insert(removeRedundantHeadingZeroes(it->str()));
        }
        return unset.size();
    }
};