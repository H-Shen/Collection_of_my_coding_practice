// https://open.kattis.com/problems/dodecaphony
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<string, int> unmap =
        {
                {"C",  1},
                {"C#", 2},
                {"D",  3},
                {"D#", 4},
                {"E",  5},
                {"F",  6},
                {"F#", 7},
                {"G",  8},
                {"G#", 9},
                {"A",  10},
                {"A#", 11},
                {"B",  12}
        };

int main() {

    int l;
    cin >> l;
    vector<string> A(l);
    vector<string> B(l);
    for (auto &i : A) {
        cin >> i;
    }
    for (auto &i : B) {
        cin >> i;
    }
    unordered_set<int> unset;
    for (int i = 0; i < l; ++i) {
        unset.insert(unmap[A.at(i)] - unmap[B.at(i)]);
    }
    if (unset.size() == 1) {
        cout << "Transposition" << endl;
        return 0;
    }

    vector<string> Inv(l);
    Inv.at(0) = A.at(0);
    for (int i = 1; i < l; ++i) {
        int gap = unmap[A.at(i)] - unmap[Inv.at(0)];
        int dist = abs(gap);
        int temp;
        temp = unmap[Inv.at(0)];
        if (gap < 0) {
            for (int j = 0; j < dist; ++j) {
                ++temp;
                if (temp > 12) {
                    temp = 1;
                }
            }
        } else {
            for (int j = 0; j < dist; ++j) {
                --temp;
                if (temp < 1) {
                    temp = 12;
                }
            }
        }
        for (const auto &[k, v] : unmap) {
            if (v == temp) {
                Inv.at(i) = k;
                break;
            }
        }
    }

    if (Inv == B) {
        cout << "Inversion" << endl;
        return 0;
    }

    auto A_rev = A;
    reverse(A_rev.begin(), A_rev.end());
    if (A_rev == B) {
        cout << "Retrograde" << endl;
        return 0;
    }

    cout << "Nonsense" << endl;
    return 0;
}
