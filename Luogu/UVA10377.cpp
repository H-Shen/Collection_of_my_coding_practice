#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {

    bool first_case = true;
    fast_io();
    int t, r, c, r_, c_, new_r, new_c;
    char face;
    bool quit_the_loop;
    string s;
    cin >> t;
    while (t--) {
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        cin >> r >> c;
        cin.get();
        vector<vector<char> > M;
        for (int i = 0; i < r; ++i) {
            getline(cin, s);
            M.emplace_back(s.begin(), s.end());
        }
        cin >> r_ >> c_;
        --r_;
        --c_;
        vector<char> instructions;
        quit_the_loop = false;
        while (true) {
            cin >> s;
            for (const auto &ch : s) {
                if (ch == 'Q') {
                    quit_the_loop = true;
                    break;
                }
                instructions.emplace_back(ch);
            }
            if (quit_the_loop) {
                break;
            }
        }
        face = 'N';
        for (const auto &ch : instructions) {
            if (ch == 'R') {
                switch (face) {
                    case 'N':
                        face = 'E';
                        break;
                    case 'S':
                        face = 'W';
                        break;
                    case 'W':
                        face = 'N';
                        break;
                    case 'E':
                        face = 'S';
                        break;
                }
            }
            else if (ch == 'L') {
                switch (face) {
                    case 'N':
                        face = 'W';
                        break;
                    case 'S':
                        face = 'E';
                        break;
                    case 'W':
                        face = 'S';
                        break;
                    case 'E':
                        face = 'N';
                        break;
                }
            }
            else {
                new_r = r_;
                new_c = c_;
                switch (face) {
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
                if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c && M.at(new_r).at(new_c) != '*') {
                    r_ = new_r;
                    c_ = new_c;
                }
            }
        }
        cout << r_ + 1 << ' ' << c_ + 1 << ' ' << face << '\n';
    }

    return 0;
}
