class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (const auto &i : ops) {
            if (i == "+") {
                int length = (int)score.size();
                score.emplace_back(score[length - 1] + score[length - 2]);
            }
            else if (i == "D") {
                score.emplace_back(score.back() * 2);
            }
            else if (i == "C") {
                score.pop_back();
            }
            else {
                score.emplace_back(stoi(i));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};