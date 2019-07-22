#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> cavityMap(vector<string> grid) {
    // Complete this function
    int len = static_cast<int>(grid.size());
    vector<vector<int> > check(static_cast<unsigned long>(len), vector<int>(static_cast<unsigned long>(len)));
    int i, j;
    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            if (i == 0 || j == 0 || i == len - 1 || j == len - 1) {
                continue;
            }
            if (grid[i][j] > grid[i][j + 1] && grid[i][j] > grid[i][j - 1]
                && grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j]) {
                check[i][j] = 1;
            }
        }
    }
    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            if (check[i][j] == 1) {
                grid[i][j] = 'X';
            }
        }
    }
    return grid;
}

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> grid(static_cast<unsigned long>(n));
    for (int grid_i = 0; grid_i < n; grid_i++) {
        cin >> grid[grid_i];
    }
    vector<string> result = cavityMap(grid);
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    return 0;
}