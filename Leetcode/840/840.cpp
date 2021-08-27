class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &A) {

        constexpr int sum = 15;
        auto checkSubgrid = [&](const vector<vector<int> > &A, size_t x, size_t y) -> bool {
            int s = 0;
            try {
                --x;
                --y;

                //uniq
                unordered_set<int> uniqElement;
                for (size_t i = x; i < x + 3; ++i) {
                    for (size_t j = y; j < y + 3; ++j) {
                        if (A.at(i).at(j) < 1 || A.at(i).at(j) > 9 || uniqElement.find(A.at(i).at(j)) != uniqElement.end()) {
                            return false;
                        }
                        uniqElement.insert(A.at(i).at(j));
                    }
                }

                //row
                for (size_t i = x; i < x + 3; ++i) {
                    s = 0;
                    for (size_t j = y; j < y + 3; ++j) {
                        s += A.at(i).at(j);
                    }
                    if (s != sum) {
                        return false;
                    }
                }

                //col
                for (size_t i = y; i < y + 3; ++i) {
                    s = 0;
                    for (size_t j = x; j < x + 3; ++j) {
                        s += A.at(j).at(i);
                    }
                    if (s != sum) {
                        return false;
                    }
                }

                //diagonal
                if (A.at(x).at(y) + A.at(x + 1).at(y + 1) + A.at(x + 2).at(y + 2) != sum) {
                    return false;
                }
                if (A.at(x + 2).at(y) + A.at(x + 1).at(y + 1) + A.at(x).at(y + 2) != sum) {
                    return false;
                }

            }
            catch (...) {
                return false;
            }
            return true;
        };

        int cnt = 0;
        for (size_t i = 0; i != A.size(); ++i) {
            for (size_t j = 0; j != A.at(i).size(); ++j) {
                if (A.at(i).at(j) == 5 && checkSubgrid(A, i, j)) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};