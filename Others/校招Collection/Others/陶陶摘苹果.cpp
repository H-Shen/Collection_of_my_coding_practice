// https://ac.nowcoder.com/acm/contest/233/A

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 10;
array<int, MAXN> A;

int main() {

    for (auto &&i : A) {
        cin >> i;
    }
    int val;
    cin >> val;
    val += 30;
    cout << count_if(begin(A), end(A), [&](const int &height) {
        return (height <= val);
    }) << endl;

    return 0;
}