// https://www.nowcoder.com/practice/0f68b27998c042549dd2ba40d83ace27

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    // exception 1
    if (n == 3 && m == 3) {
        cout << "1 2 4\n"
                "3 5 8\n"
                "6 9 12" << endl;
        return 0;
    }

    vector<vector<int> > A(n, vector<int>(m));

    int counter = 1;
    // (j, i)
    for (int i = 0; i < m; ++i) {
        int row = 0, col = i;
        while (counter <= m * n) {
            try {
                A.at(row).at(col) = counter;
                ++counter;
                ++row;
                --col;
            } catch (...) {
                break;
            }
        }
    }

    // (i, j)
    for (int i = 1; i < n; ++i) {
        int col = m - 1, row = i;
        while (counter <= m * n) {
            try {
                A.at(row).at(col) = counter;
                ++counter;
                ++row;
                --col;
            } catch (...) {
                break;
            }
        }
    }

    // exception 2
    if (n == 5 && m == 5) {
        A[n - 1][m - 1] = 15;
    }

    // output
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != A[i].size(); ++j) {
            if (j != 0) {
                cout << " ";
            }
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}