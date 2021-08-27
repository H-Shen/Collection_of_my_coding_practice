class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = (int)students.size();
        int m = (int)students[0].size();
        vector<int> vec;
        int maxScore = 0;
        int currentScore;
        for (int i = 0; i < n; ++i) vec.emplace_back(i);
        do {
            currentScore = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (students[vec[i]][j] == mentors[i][j]) {
                        ++currentScore;
                    }
                }
            }
            maxScore = max(maxScore, currentScore);
        } while (next_permutation(vec.begin(),vec.end()));
        return maxScore;
    }
};