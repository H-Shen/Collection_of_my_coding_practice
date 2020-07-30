#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
vector<int> parse(const vector<char> &obj) {
    vector<int> result;
    string last;
    for (const auto &ch : obj) {
        if (ch == '.') {
            last.push_back(ch);
        } else {
            if (!last.empty()) {
                result.emplace_back(last.size());
                last.clear();
            }
        }
    }
    if (!last.empty()) {
        result.emplace_back(last.size());
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<char> > M;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    int counter = 0;
    if (k == 1) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (M.at(i).at(j) == '.') {
                    ++counter;
                }
            }
        }
    } else {
        vector<int> temp_vec;
        // rows
        for (int i = 0; i < r; ++i) {
            temp_vec = parse(M.at(i));
            for (const auto &j : temp_vec) {
                if (j >= k) {
                    counter += (j - k + 1);
                }
            }
        }
        // cols
        for (int i = 0; i < c; ++i) {
            vector<char> temp_char_vec;
            for (int j = 0; j < r; ++j) {
                temp_char_vec.emplace_back(M.at(j).at(i));
            }
            temp_vec = parse(temp_char_vec);
            for (const auto &j : temp_vec) {
                if (j >= k) {
                    counter += (j - k + 1);
                }
            }
        }
    }
    cout << counter << '\n';

    return 0;
}