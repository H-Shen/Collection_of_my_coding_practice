// https://www.nowcoder.com/practice/053875842995497e937ac58f65cddfae

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void adjust(vector<vector<int> > &a, int n) {
    int i, j, maxVal;
    int counter = 0;
    vector<int> save(static_cast<unsigned long>(n));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            save[j] = a[j][i];
        }
        maxVal = *max_element(save.begin() + counter, save.end());
        for (j = 0; j < n; j++) {
            if (save[j] == maxVal) {
                break;
            }
        }
        if (i != n - 1)
            swap_ranges(a[j].begin(), a[j].end(), a[counter].begin());
        counter++;
        save.clear();
        save.resize(static_cast<unsigned long>(n));
    }
}

int main() {
    int n, i, j;
    while (cin >> n) {
        vector<vector<int> > a(static_cast<unsigned long>(n));
        for (i = 0; i < n; i++) {
            a[i].resize(static_cast<unsigned long>(n));
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        adjust(a, n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j != n - 1)
                    cout << a[i][j] << ' ';
                else
                    cout << a[i][j] << endl;
            }
        }
    }
    return 0;
}