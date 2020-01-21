#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    string s;
    cin >> s;
    copy(s.rbegin(), s.rend(), ostream_iterator<char>(cout, ""));

    return 0;
}