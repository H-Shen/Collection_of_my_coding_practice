#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

constexpr int MAX_SIZE = 15;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int r, c, r_, c_, new_r, new_c, bak_r_, bak_c_, counter, steps_before_cycle, cycle_r, cycle_c;
    string s;
    while (true) {
        cin >> r >> c >> c_;
        if (r == 0 && c == 0 && c_ == 0) break;
        r_ = 0;
        c_ = c_ - 1;
        // trivial case
        if (c_ < 0 || c_ >= c) {
            cout << "0 step(s) to exit" << '\n';
            continue;
        }
        bak_r_ = r_;
        bak_c_ = c_;
        vector<vector<char> > M;
        for (int i = 0; i < r; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
        }
        bitset<MAX_SIZE> vis[MAX_SIZE];
        counter = 0;
        vis[r_][c_] = true;
        while (true) {
            new_r = r_;
            new_c = c_;
            switch (M.at(r_).at(c_)) {
                case 'N':
                    --new_r;
                    break;
                case 'S':
                    ++new_r;
                    break;
                case 'W':
                    --new_c;
                    break;
                case 'E':
                    ++new_c;
                    break;
            }
            ++counter;
            if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c) {
                r_ = new_r;
                c_ = new_c;
                if (vis[r_][c_]) {
                    steps_before_cycle = 0;
                    cycle_r = r_;
                    cycle_c = c_;
                    // calculate the steps before the loop
                    r_ = bak_r_;
                    c_ = bak_c_;
                    while (true) {
                        if (r_ == cycle_r && c_ == cycle_c) {
                            break;
                        }
                        new_r = r_;
                        new_c = c_;
                        switch (M.at(r_).at(c_)) {
                            case 'N':
                                --new_r;
                                break;
                            case 'S':
                                ++new_r;
                                break;
                            case 'W':
                                --new_c;
                                break;
                            case 'E':
                                ++new_c;
                                break;
                        }
                        ++steps_before_cycle;
                        r_ = new_r;
                        c_ = new_c;
                    }
                    cout << steps_before_cycle << " step(s) before a loop of "
                         << counter - steps_before_cycle << " step(s)" << '\n';
                    break;
                } else {
                    vis[r_][c_] = true;
                }
            } else {
                cout << counter << " step(s) to exit" << '\n';
                break;
            }
        }
    }

    return 0;
}
