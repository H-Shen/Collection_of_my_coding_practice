// https://open.kattis.com/problems/joinstrings
//
#include <bits/extc++.h>

using namespace std;

vector<string> A;
vector<list<int> > B;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;
    A.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A.at(i);
    }
    B.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        B.at(i).push_front(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        B.at(a).splice(B.at(a).end(), B.at(b));
    }
    for (size_t index = 1; index != B.size(); ++index) {
        for (const auto &j : B.at(index)) {
            cout << A.at(j);
        }
    }
    cout << '\n';
    
    return 0;
}
