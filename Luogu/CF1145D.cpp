#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    cout << (A.at(2) ^ (*min_element(A.begin(), A.end()))) + 2 << '\n';

    return 0;
}