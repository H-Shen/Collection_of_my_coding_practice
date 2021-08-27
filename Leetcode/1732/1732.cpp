class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start = 0;
        int answer = start;
        for (const auto &i : gain) {
            start = start + i;
            answer = max(start, answer);
        }
        return answer;
    }
};