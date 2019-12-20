// https://www.nowcoder.com/practice/ebe941260f8c4210aa8c17e99cbc663b

#include <vector>
#include <iostream>

using namespace std;

void matrix_multiply(vector<vector<int> > &a, vector<vector<int> > &b, vector<vector<int> > &c, int x, int y, int z) {
    int i, j, k;
    for (i = 0; i < x; i++) {
        for (j = 0; j < z; j++) {
            for (k = 0; k < y; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    int x, y, z, i, j;
    while (cin >> x >> y >> z) {
        vector<vector<int> > a(static_cast<unsigned long>(x));
        for (i = 0; i < x; i++) {
            a[i].resize(static_cast<unsigned long>(y));
            for (j = 0; j < y; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int> > b(static_cast<unsigned long>(y));
        for (i = 0; i < y; i++) {
            b[i].resize(static_cast<unsigned long>(z));
            for (j = 0; j < z; j++) {
                cin >> b[i][j];
            }
        }

        vector<vector<int> > c(static_cast<unsigned long>(x));
        for (i = 0; i < x; i++) {
            c[i].resize(static_cast<unsigned long>(z));
        }

        matrix_multiply(a, b, c, x, y, z);
        for (i = 0; i < x; i++) {
            for (j = 0; j < z; j++) {
                if (j == z - 1)
                    cout << c[i][j] << endl;
                else
                    cout << c[i][j] << ' ';
            }
        }
    }
    return 0;
}