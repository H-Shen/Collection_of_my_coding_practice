#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    unordered_map<char, int> A;
    A[' '] = 1;
    A['a'] = 1;A['b'] = 2;A['c'] = 3;
    A['d'] = 1;A['e'] = 2;A['f'] = 3;
    A['g'] = 1;A['h'] = 2;A['i'] = 3;
    A['j'] = 1;A['k'] = 2;A['l'] = 3;
    A['m'] = 1;A['n'] = 2;A['o'] = 3;
    A['p'] = 1;A['q'] = 2;A['r'] = 3;A['s'] = 4;
    A['t'] = 1;A['u'] = 2;A['v'] = 3;
    A['w'] = 1;A['x'] = 2;A['y'] = 3;A['z'] = 4;

    string s;
    getline(cin, s);
    int counter = 0;
    for (const char &ch : s) {
        counter += A[ch];
    }
    cout << counter << endl;

    return 0;
}
