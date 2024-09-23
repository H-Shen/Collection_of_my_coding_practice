// https://www.nowcoder.com/practice/3afe6fabdb2c46ed98f06cfd9a20f2ce

#include <algorithm>

using namespace std;

class Finder {
public:
    vector<int> findElement(vector <vector<int>> mat, int n, int m, int x) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (binary_search(mat[i].begin(), mat[i].end(), x)) {
                for (int j = 0; j < m; j++) {
                    if (mat.at(i).at(j) == x) {
                        res.emplace_back(i);
                        res.emplace_back(j);
                        return res;
                    }
                }

            }
        }
        return {-1, -1};
    }
};