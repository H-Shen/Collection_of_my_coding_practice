#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<vector<int> > A(n, vector<int>(n, -1));
    int i = 0, j = (n - 1) / 2, val = 1;
    A.at(i).at(j) = val;
    ++val;
    bool on_the_first_row = i == 0;
    bool on_the_last_col = j == n - 1;
    while (val <= n * n) {
        if (on_the_first_row && on_the_last_col) {
            ++i;
            A.at(i).at(j) = val;
        }
        else if (on_the_first_row) {
            i = n - 1;
            ++j;
            A.at(i).at(j) = val;
        }
        else if (on_the_last_col) {
            j = 0;
            --i;
            A.at(i).at(j) = val;
        }
        else {
            if (A.at(i - 1).at(j + 1) == -1) {
                --i;
                ++j;
                A.at(i).at(j) = val;
            } else {
                ++i;
                A.at(i).at(j) = val;
            }
        }
        on_the_first_row = i == 0;
        on_the_last_col = j == n - 1;
        ++val;
    }
    bool firstItem;
    for (const auto &row : A) {
        firstItem = true;
        for (const auto &item : row) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", item);
        }
        printf("\n");
    }

    return 0;
}
