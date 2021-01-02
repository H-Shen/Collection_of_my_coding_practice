// N-queen solution with bitset
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int total_counter;
int counter;
vector<int> answer;
int n;

void dfs(int row, int col, int leftDiagonal, int rightDiagonal) {
    if (row >= n) {
        // output
        if (counter < 3) {
            bool firstItem = true;
            for (int i = 0; i < n; ++i) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << ' ';
                }
                cout << answer[i];
            }
            cout << '\n';
            ++counter;
        }
        ++total_counter;
    }
    int bits = (~(col | leftDiagonal | rightDiagonal)) & ((1 << n) - 1);
    while (bits > 0) {
        int lowbit = bits & (-bits); // p
        answer[row] = (int)log2(lowbit) + 1;
        int newCol = col | lowbit;
        int newLeftDiagonal = (leftDiagonal | lowbit) << 1;
        int newRightDiagonal = (rightDiagonal | lowbit) >> 1;
        int newRow = row + 1;
        dfs(newRow, newCol, newLeftDiagonal, newRightDiagonal);
        // set the right-most 1 to zero
        bits = bits & (bits - 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    answer.resize(n);
    dfs(0, 0, 0, 0);
    cout << total_counter << '\n';

    return 0;
}
