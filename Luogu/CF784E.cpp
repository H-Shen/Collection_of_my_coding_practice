#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 3;

int main() {

    int iIn1, iIn2, iIn3, iIn4;
    cin >> iIn1 >> iIn2 >> iIn3 >> iIn4;
    cout << ( ((iIn1^iIn2) & (iIn3 | iIn4)) ^ ((iIn2&iIn3) | (iIn1^iIn4)) ) << '\n';

    return 0;
}
