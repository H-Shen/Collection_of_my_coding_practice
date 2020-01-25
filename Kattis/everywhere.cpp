// https://open.kattis.com/problems/everywhere
#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    string place;
    cin >> n;
    while (n--) {
        cin >> m;
        unordered_set<string> A;
        while (m--) {
            cin >> place;
            A.insert(place);
        }
        cout << A.size() << endl;
    }
    return 0;
}
