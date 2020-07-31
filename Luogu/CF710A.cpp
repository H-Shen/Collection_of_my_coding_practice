#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int STEPS = 8;
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int main() {

    string s;
    cin >> s;
    int i = 8 - (s.back() - '0');
    int j = s.front() - 'a';
    int counter = 0;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            ++counter;
        }
    }
    cout << counter << '\n';
    return 0;
}