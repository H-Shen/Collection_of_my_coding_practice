#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int current = h * 3600 + m * 60 + s;
    scanf("%d:%d:%d", &h, &m, &s);
    int final = h * 3600 + m * 60 + s;
    if (final <= current) {
        final += 24 * 3600;
    }
    int gap = final - current;
    h = gap / 3600;
    m = (gap - h * 3600) / 60;
    s = gap - h * 3600 - m * 60;
    string h_str = to_string(h);
    string m_str = to_string(m);
    string s_str = to_string(s);
    if (h_str.size() < 2) h_str = "0" + h_str;
    if (m_str.size() < 2) m_str = "0" + m_str;
    if (s_str.size() < 2) s_str = "0" + s_str;
    printf("%s:%s:%s\n", h_str.c_str(), m_str.c_str(), s_str.c_str());
    return 0;
}