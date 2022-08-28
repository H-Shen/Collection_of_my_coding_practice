class Solution {
public:
    string removeStars(string s) {
        deque<char> dq;
        int numberOfStars = 0;
        while (!s.empty()) {
            if (s.back() == '*') {
                s.pop_back();
                ++numberOfStars;
            }
            else {
                if (numberOfStars > 0) {
                    --numberOfStars;
                }
                else {
                    dq.push_front(s.back());
                }
                s.pop_back();
            }
        }
        return string(dq.begin(),dq.end());
    }
};