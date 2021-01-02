#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 25;

vector<vector<int> > solutions;
vector<int> answer;

void dfs(int row, int col, int leftDiagonal, int rightDiagonal, int n) {
    if (row >= n) {
        solutions.emplace_back(answer);
    }
    int bits = (~(col | leftDiagonal | rightDiagonal)) & ((1 << n) - 1);
    while (bits > 0) {
        int lowbit = bits & (-bits);
        answer[row] = (int)log2(lowbit);
        int newCol = col | lowbit;
        int newLeftDiagonal = (leftDiagonal | lowbit) << 1;
        int newRightDiagonal = (rightDiagonal | lowbit) >> 1;
        int newRow = row + 1;
        dfs(newRow, newCol, newLeftDiagonal, newRightDiagonal, n);
        // set the right-most 1 to zero
        bits = bits & (bits - 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, counter;
    cin >> n;
    vector<int>().swap(answer);
    answer.resize(n);
    dfs(0, 0, 0, 0, n);
    bitset<MAXN> holes[MAXN];
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s.at(j) == '.') {
                holes[i][j] = true;
            }
        }
    }
    counter = (int)solutions.size();
    for (const auto &solution : solutions) {
        for (size_t j = 0; j != solution.size(); ++j) {
            if (holes[j][solution.at(j)]) {
                --counter;
                break;
            }
        }
    }
    cout << counter << '\n';

    return 0;
}