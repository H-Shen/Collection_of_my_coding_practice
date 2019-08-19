#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, i, j;
    char c;
    cin >> n >> c;

    int width = n;
    int height;
    if (width % 2 == 0) {
        height = width / 2;
    } else {
        height = (width + 1) / 2;
    }

    for (i = 0; i < height; ++i) {
        if (i == 0 || i == height - 1) {
            for (j = 0; j < width; ++j) {
                cout << c;
            }
        } else {
            cout << c;
            for (j = 1; j < width - 1; ++j) {
                cout << ' ';
            }
            cout << c;
        }
        cout << endl;
    }

    return 0;
}