// https://www.nowcoder.com/practice/2f8c17bec47e416897ce4b9aa560b7f4

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int ROW_LENGTH = 9, COLUMN_LENGTH = 9;

int main() {
    ios_base::sync_with_stdio(false);
    int m, n;
    while (cin >> m >> n) {

        if (m < 0 || m > ROW_LENGTH || n < 0 || n > COLUMN_LENGTH) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        vector<vector<int> > A(static_cast<unsigned long>(m), vector<int>(static_cast<unsigned long>(n)));

        int x0, y0, x1, y1;
        cin >> y0 >> x0 >> y1 >> x1;
        try {
            swap(A.at(static_cast<unsigned long>(y0)).at(static_cast<unsigned long>(x0)), A.at(
                    static_cast<unsigned long>(y1)).at(static_cast<unsigned long>(x1)));
            cout << 0 << endl;
        } catch (...) {
            cout << -1 << endl;
        }

        int insertRow;
        cin >> insertRow;
        if (insertRow < 0 || insertRow >= m) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
            A.resize(m + insertRow);
        }

        int insertCol;
        cin >> insertCol;
        if (insertCol < 0 || insertCol >= n) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
            for_each(A.begin(), A.end(), [&](vector<int> &s) { s.resize(n + insertCol); });
        }

        int y2, x2;
        cin >> y2 >> x2;
        if (y2 < 0 || y2 >= m || x2 < 0 || x2 >= n) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}