// https://open.kattis.com/problems/eyeofsauron

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int left = (int)s.find('(');
    int right = (int)s.size() - (int)s.find(')') - 1;
    if (left == right) {
        cout << "correct" << '\n';
    } else {
        cout << "fix" << '\n';
    }
    return 0;
}
