#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int q, y, x;
    cin >> q;
    set<int> A;
    for (int i = 0; i < q; i++) {
        cin >> y >> x;
        switch (y) {
            case 1:
                A.insert(x);
                break;
            case 2:
                A.erase(x);
                break;
            default:
                if (A.find(x) != A.end())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
    }
    return 0;
}
