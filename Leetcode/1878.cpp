class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        auto getSum = [&](int i, int j, int w) {
            int sum = 0;
            try {
                if (w == 1) {
                    return grid.at(i).at(j);
                }
                for (int I = i, J = j; I >= i - (w - 1); --I, ++J) {
                    sum += grid.at(I).at(J);
                }
                for (int I = i, J = j; I <= i + (w - 1); ++I, ++J) {
                    sum += grid.at(I).at(J);
                }
                for (int I = i - (w - 1), J = j + (w - 1); I <= i; ++I, ++J) {
                    sum += grid.at(I).at(J);
                }
                for (int I = i + (w - 1), J = j + (w - 1); I >= i; --I, ++J) {
                    sum += grid.at(I).at(J);
                }
            } catch (...) {
                return 0;
            }
            return sum 
                - grid.at(i).at(j) 
                - grid.at(i-(w-1)).at(j+(w-1))
                - grid.at(i+(w-1)).at(j+(w-1))
                - grid.at(i).at(j+2*(w-1));
        };
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        vector<int> ans;
        int sum, w;
        bool outOfRange;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                w = 1;
                outOfRange = false;
                while (!outOfRange) {
                    sum = 0;
                    try {
                        if (w == 1) {
                            sum = grid.at(i).at(j);
                            ans.emplace_back(sum);
                            ++w;
                            continue;
                        }
                        for (int I = i, J = j; I >= i - (w - 1); --I, ++J) {
                            sum += grid.at(I).at(J);
                        }
                        for (int I = i, J = j; I <= i + (w - 1); ++I, ++J) {
                            sum += grid.at(I).at(J);
                        }
                        for (int I = i - (w - 1), J = j + (w - 1); I <= i; ++I, ++J) {
                            sum += grid.at(I).at(J);
                        }
                        for (int I = i + (w - 1), J = j + (w - 1); I >= i; --I, ++J) {
                            sum += grid.at(I).at(J);
                        }
                    } catch (...) {
                        outOfRange = true;
                        continue;
                    }
                    sum = sum 
                    - grid.at(i).at(j) 
                    - grid.at(i-(w-1)).at(j+(w-1))
                    - grid.at(i+(w-1)).at(j+(w-1))
                    - grid.at(i).at(j+2*(w-1));
                    ans.emplace_back(sum);
                    ++w;
                }
            }
        }
        sort(ans.begin(), ans.end(), greater<>());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        if (ans.size() < 3) {
            return ans;
        }
        return vector<int>(ans.begin(), ans.begin()+3);
    }
};