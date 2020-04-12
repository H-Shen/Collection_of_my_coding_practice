#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline string word = "yizhong";
int length = static_cast<int>(word.size());

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char> > A(n, vector<char>(n));
    vector<vector<char> > B(n, vector<char>(n, '*'));
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            A.at(i).at(j) = s.at(j);
        }
    }
    int cur_i, cur_j;
    bool haveAns;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // right
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    ++cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    ++cur_j;
                }
            }
            // left
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    --cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    --cur_j;
                }
            }
            // up
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    --cur_i;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    --cur_i;
                }
            }
            // down
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    ++cur_i;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    ++cur_i;
                }
            }
            // upper-left
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    --cur_i;
                    --cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    --cur_i;
                    --cur_j;
                }
            }
            // upper-right
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    --cur_i;
                    ++cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    --cur_i;
                    ++cur_j;
                }
            }
            // lower-left
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    ++cur_i;
                    --cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    ++cur_i;
                    --cur_j;
                }
            }
            // lower-right
            try {
                cur_i = i;
                cur_j = j;
                haveAns = true;
                for (int k = 0; k < length; ++k) {
                    if (A.at(cur_i).at(cur_j) != word.at(k)) {
                        haveAns = false;
                        break;
                    }
                    ++cur_i;
                    ++cur_j;
                }
            } catch (...) {
                haveAns = false;
            }
            if (haveAns) {
                cur_i = i;
                cur_j = j;
                for (int k = 0; k < length; ++k) {
                    B.at(cur_i).at(cur_j) = word.at(k);
                    ++cur_i;
                    ++cur_j;
                }
            }
        }
    }
    for (const auto &i : B) {
        cout << string(i.begin(), i.end()) << '\n';
    }

    return 0;
}