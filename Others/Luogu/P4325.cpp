#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int mod = 42, maxn = 10;

int main()
{
    ios_base::sync_with_stdio(false);
    unordered_set <int> A;
    int val;
    for (int i = 0; i < maxn; ++i)
    {
        cin >> val;
        A.insert(val % mod);
    }
    cout << A.size() << endl;
    return 0;
}

