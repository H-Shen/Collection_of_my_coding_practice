#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    int sum = 0;
    while (n--) {
        cin >> s;
        if (s == "Icosahedron") {
            sum += 20;
        } else if (s == "Cube") {
            sum += 6;
        } else if (s == "Tetrahedron") {
            sum += 4;
        } else if (s == "Dodecahedron") {
            sum += 12;
        } else {
            sum += 8;
        }
    }
    cout << sum << '\n';

    return 0;
}
