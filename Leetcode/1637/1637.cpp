class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> temp;
        for (const auto &i : points) {
            temp.emplace_back(i.front());
        }
        sort(temp.begin(), temp.end());
        int answer = -1;
        for (size_t i = 1; i != temp.size(); ++i) {
            answer = max(answer, temp.at(i) - temp.at(i - 1));
        }
        return answer;
    }
};