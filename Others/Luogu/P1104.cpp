#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    string a;
    int y, m, d;
    int id;
};

int main() {

    int n;
    cin >> n;
    vector<Node> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].a >> A[i].y >> A[i].m >> A[i].d;
        A[i].id = i;
    }
    sort(A.begin(), A.end(), [](const Node &l, const Node &r) {
        if (l.y == r.y) {
            if (l.m == r.m) {
                if (l.d == r.d) {
                    return (l.id > r.id);
                }
                return (l.d < r.d);
            }
            return (l.m < r.m);
        }
        return (l.y < r.y);
    });
    for (const auto &i : A) {
        cout << i.a << '\n';
    }


    return 0;
}

