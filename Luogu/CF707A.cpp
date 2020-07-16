#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int total = n * m;
    string s;
    for (int i = 0; i < total; ++i) {
        cin >> s;
        if (s != "W" && s != "B" && s != "G") {
            cout << "#Color" << '\n';
            return 0;
        }
    }
    cout << "#Black&White" << '\n';

    return 0;
}
