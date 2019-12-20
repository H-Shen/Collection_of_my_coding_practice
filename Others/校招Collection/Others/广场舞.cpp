// https://www.nowcoder.com/practice/e0bf18f0ca654ff091ef61c33330d61f

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int m, n;
    int i, j, maxVal, minVal;

    while (cin >> m >> n) {

        vector<vector<int> > a(static_cast<unsigned long>(m));
        for (i = 0; i < m; i++) {
            a[i].resize(static_cast<unsigned long>(n));
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int> > a_rotate(static_cast<unsigned long>(n));
        for (i = 0; i < n; i++) {
            a_rotate[i].resize(static_cast<unsigned long>(m));
            for (j = 0; j < m; j++) {
                a_rotate[i][j] = a[j][i];
            }
        }

        vector<int> rowMax(static_cast<unsigned long>(m));
        for (i = 0; i < m; i++) {
            maxVal = *max_element(a[i].begin(), a[i].end());
            rowMax[i] = maxVal;
        }

        vector<int> colMin(static_cast<unsigned long>(n));
        for (i = 0; i < n; i++) {
            minVal = *min_element(a_rotate[i].begin(), a_rotate[i].end());
            colMin[i] = minVal;
        }

        bool hasAns = false;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (rowMax[i] == colMin[j]) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    hasAns = true;
                }
            }
        }

        if (!hasAns)
            cout << "No Point" << endl;
        cout << endl;

    }
    return 0;
}