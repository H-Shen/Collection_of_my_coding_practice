class Solution {
public:
    int maxDepth(string s) {
        int sta = 0;
        int answer = 0;
        for (const auto &ch : s) {
            if (ch == '(') {
                ++sta;
                answer = max(answer, sta);
            }
            else if (ch == ')') {
                --sta;
            }
        }
        return answer;
    }
};