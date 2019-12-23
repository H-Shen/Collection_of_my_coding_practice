// https://open.kattis.com/problems/vauvau
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1005;

inline static
vector<bool> getPattern(int a, int b) {
    vector<bool> dogA(MAXN);
    bool change = true;
    int counter = 0;
    for (size_t i = 1; i <= MAXN - 1; ++i) {
        if (counter == 0) {
            if (change) {
                counter = a;
            } else {
                counter = b;
            }
            change = !change;
        }
        dogA.at(i) = !change;
        --counter;
    }
    return dogA;
}

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<size_t> arriveTime(3);
    for (auto &&i : arriveTime) {
        cin >> i;
    }

    // aggressive: true
    // calm: false
    auto dogA = getPattern(a, b);
    auto dogB = getPattern(c, d);
    for (const auto &i : arriveTime) {
        if (dogA.at(i) && dogB.at(i)) {
            cout << "both" << endl;
        } else if (dogA.at(i) || dogB.at(i)) {
            cout << "one" << endl;
        } else {
            cout << "none" << endl;
        }
    }


    return 0;
}
