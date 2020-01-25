// https://open.kattis.com/problems/yoda

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string n, m;
    cin >> n >> m;
    size_t len = max(n.size(), m.size());
    if (n.size() < len) {
        n = string(len - n.size(), '0') + n;
    }
    if (m.size() < len) {
        m = string(len - m.size(), '0') + m;
    }
    vector<char> n_arr(n.begin(), n.end());
    vector<char> m_arr(m.begin(), m.end());
    for (size_t i = 0; i < len; ++i) {
        if (n_arr[i] > m_arr[i]) {
            m_arr[i] = '\0';
        } else if (n_arr[i] < m_arr[i]) {
            n_arr[i] = '\0';
        }
    }
    string n_ans, m_ans;
    for (size_t i = 0; i < len; ++i) {
        if (n_arr[i] != '\0') {
            n_ans = n_ans + n_arr[i];
        }
    }
    for (size_t i = 0; i < len; ++i) {
        if (m_arr[i] != '\0') {
            m_ans = m_ans + m_arr[i];
        }
    }
    if (n_ans == "") {
        cout << "YODA" << endl;
    } else {
        cout << stol(n_ans) << endl;
    }
    if (m_ans == "") {
        cout << "YODA" << endl;
    } else {
        cout << stol(m_ans) << endl;
    }
    return 0;
}
