#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int s, v;
    cin >> s >> v;
    int time = 10;
    while (s > 0) {
        ++time;
        s -= v;
    }
    int a = 8 * 60 - time;
    int m, h;
    if (a < 0) {
        a += 24 * 60;
    }
    m = a % 60;
    h = a / 60;
    string h_s = to_string(h);
    if (h_s.size() == 1) {
        h_s = '0' + h_s;
    }
    string m_s = to_string(m);
    if (m_s.size() == 1) {
        m_s = '0' + m_s;
    }
    cout << h_s << ':' << m_s << endl;

    return 0;
}
