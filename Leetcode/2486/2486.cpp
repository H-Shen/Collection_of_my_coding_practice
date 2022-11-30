class Solution {
public:
    int appendCharacters(string s, string t) {
        deque<char> dq(t.begin(),t.end());
        for (const auto &i : s) {
            if (dq.empty()) {
                break;
            }
            if (i == dq.front()) {
                dq.pop_front();
            }
        }
        return (int)dq.size();
    }
};