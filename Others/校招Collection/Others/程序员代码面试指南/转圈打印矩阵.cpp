// https://www.nowcoder.com/practice/8ae3701849ae450dac56ad2b704fa57d

#include <bits/stdc++.h>

using namespace std;

vector<int> printMatrix(vector<vector<int> > mat) {

    vector<int> result;
    int n = static_cast<int>(mat.size());
    if (n == 0) {
        return result;
    }

    int m = static_cast<int>(mat[0].size());
    if (m == 0) {
        return result;
    }

    int leftCorneri = 0;
    int leftCornerj = 0;
    int rightCorneri = n - 1;
    int rightCornerj = m - 1;
    int counter = 0;
    int total = n * m;
    int i;

    if (n == 1) {
        for (i = 0; i <= m - 1; i++) {
            result.emplace_back(mat[0][i]);
        }
    } else if (m == 1) {
        for (i = 0; i <= n - 1; i++) {
            result.emplace_back(mat[i][0]);
        }
    } else {
        while (true) {
            for (i = leftCorneri; i <= rightCornerj; i++) {
                result.push_back(mat[leftCorneri][i]);
                ++counter;
            }
            if (counter == total)
                break;
            for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                result.push_back(mat[i][rightCornerj]);
                ++counter;
            }
            if (counter == total)
                break;
            for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                result.push_back(mat[rightCorneri][i]);
                ++counter;
            }
            if (counter == total)
                break;
            for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                result.push_back(mat[i][leftCornerj]);
                ++counter;
            }
            if (counter == total)
                break;
            ++leftCorneri;
            ++leftCornerj;
            --rightCorneri;
            --rightCornerj;
        }
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(n, vector<int>(m));
    for (auto &&i : A) {
        for (auto &&j : i) {
            cin >> j;
        }
    }
    auto result{printMatrix(A)};
    bool firstItem{true};
    for (const auto &i : result) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;
    return 0;
}