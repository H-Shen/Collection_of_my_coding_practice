#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {
    string s;
    cin >> s;
    cout << (s.back() - '0') % 2 << endl;
    return 0;
}