#include <bits/stdc++.h>

// https://www.nowcoder.com/practice/ba241b85371c409ea01ac0aa1a8d957b

using namespace std;

const int MAXN = 30000;
vector<int> A;

int main() {

    // pre
    for (int i = 7; i <= MAXN; ++i) {
        if (i % 7 == 0 || to_string(i).find('7') != string::npos) {
            A.emplace_back(i);
        }
    }

    int N;
    while (cin >> N) {
        cout << upper_bound(A.begin(), A.end(), N) - A.begin() << endl;
    }
    return 0;
}