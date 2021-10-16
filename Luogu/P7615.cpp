#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int STEPS = 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c;
vector<vector<char>> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c;
    vec.resize(r);
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        vector<char> temp(s.begin(),s.end());
        vec[i] = temp;
    }
    int new_i, new_j, counter;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (vec[i][j] == '.') {
                counter = 0;
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
                        vec[new_i][new_j] == '.') {
                        ++counter;
                    }
                }
                if (counter == 1) {
                    cout << 1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}