inline static
vector<vector<char> > rotateRight(const vector<vector<char> > &s) {
    if (s.empty() || s.front().empty()) {
        return vector<vector<char> >();
    }
    vector<vector<char> > result(s.front().size(), vector<char>(s.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = s.at(s.size() - 1 - j).at(i);
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        auto A = rotateRight(box);
        int R = (int)A.size();
        int C = (int)A[0].size();
        for (int col = 0; col < C; ++col) {
            vector<int> obstaclesPosition = {-1};
            for (int row = 0; row < R; ++row) {
                if (A.at(row).at(col) == '*') {
                    obstaclesPosition.emplace_back(row);
                }
            }
            obstaclesPosition.emplace_back(R);
            int length = (int)obstaclesPosition.size();
            int counter;
            for (int i = 0; i < length - 1; ++i) {
                if (obstaclesPosition.at(i + 1) - obstaclesPosition.at(i) <= 1) {
                    continue;
                }
                counter = 0;
                // count the apples, erase the apples in a column
                for (int j = obstaclesPosition.at(i) + 1; j <= obstaclesPosition.at(i + 1) - 1; ++j) {
                    if (A.at(j).at(col) == '#') {
                        ++counter;
                        A.at(j).at(col) = '.';
                    }
                }
                // re-allocate the apples in a column
                for (int j = obstaclesPosition.at(i + 1) - 1; counter > 0; --counter, --j) {
                    A.at(j).at(col) = '#';
                }
            }
        }
        return A;
    }
};