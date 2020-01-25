// https://open.kattis.com/problems/set
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 12;
vector<unordered_set<string> > A;

void pre(string s) {
    unordered_set<string> temp_set;
    for (const char &i : s) {
        temp_set.insert(string(3, i));
    }
    sort(s.begin(), s.end());
    do {
        temp_set.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    A.emplace_back(temp_set);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // pre
    pre("123");
    pre("DSO");
    pre("STO");
    pre("RGP");

    // input
    vector<string> L(MAXN);
    for (auto &i : L) {
        cin >> i;
    }
    string property0;
    string property1;
    string property2;
    string property3;
    vector<tuple<int, int, int> > output;
    for (int i = 0; i < MAXN - 2; ++i) {
        for (int j = i + 1; j < MAXN - 1; ++j) {
            for (int k = j + 1; k < MAXN; ++k) {

                property0 = "";
                property0.push_back(L.at(i).at(0));
                property0.push_back(L.at(j).at(0));
                property0.push_back(L.at(k).at(0));
                if (A.at(0).find(property0) == A.at(0).end()) {
                    continue;
                }

                property1 = "";
                property1.push_back(L.at(i).at(1));
                property1.push_back(L.at(j).at(1));
                property1.push_back(L.at(k).at(1));
                if (A.at(1).find(property1) == A.at(1).end()) {
                    continue;
                }

                property2 = "";
                property2.push_back(L.at(i).at(2));
                property2.push_back(L.at(j).at(2));
                property2.push_back(L.at(k).at(2));
                if (A.at(2).find(property2) == A.at(2).end()) {
                    continue;
                }

                property3 = "";
                property3.push_back(L.at(i).at(3));
                property3.push_back(L.at(j).at(3));
                property3.push_back(L.at(k).at(3));
                if (A.at(3).find(property3) == A.at(3).end()) {
                    continue;
                }
                output.emplace_back(i + 1, j + 1, k + 1);
            }
        }
    }

    if (output.empty()) {
        cout << "no sets" << '\n';
    } else {
        sort(output.begin(), output.end(), [](const tuple<int, int, int> &lhs,
                                              const tuple<int, int, int> &rhs) {
            if (get<0>(lhs) == get<0>(rhs)) {
                if (get<1>(lhs) == get<1>(rhs)) {
                    return (get<2>(lhs) < get<2>(rhs));
                }
                return (get<1>(lhs) < get<1>(rhs));
            }
            return (get<0>(lhs) < get<0>(rhs));
        });
        for (const auto &i : output) {
            cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
        }
    }
    return 0;
}
