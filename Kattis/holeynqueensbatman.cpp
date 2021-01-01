// https://open.kattis.com/problems/holeynqueensbatman
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 15;
vector<vector<vector<int> > > solutions(MAXN);
vector<int> answer;

void dfs(int row, int col, int leftDiagonal, int rightDiagonal, int n) {
    if (row >= n) {
        solutions.at(n).emplace_back(answer);
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

    int n, m, counter, u, v;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        if (solutions.at(n).empty()) {
            vector<int>().swap(answer);
            answer.resize(n);
            dfs(0, 0, 0, 0, n);
        }
        bitset<MAXN> holes[MAXN];
        while (m--) {
            cin >> u >> v;
            holes[u][v] = true;
        }
        counter = (int)solutions.at(n).size();
        for (const auto &solution : solutions.at(n)) {
            for (size_t j = 0; j != solution.size(); ++j) {
                if (holes[j][solution.at(j)]) {
                    --counter;
                    break;
                }
            }
        }
        cout << counter << '\n';
    }
    return 0;
}
