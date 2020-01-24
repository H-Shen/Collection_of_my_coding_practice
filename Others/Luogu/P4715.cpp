#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Country {
    int id;
    int ability;
};

int pre[] = {1, 2, 4, 8, 16, 32, 64, 128};

int main() {

    int n;
    scanf("%d", &n);
    n = pre[n];
    vector<Country> A(n);
    for (int i = 1; i <= n; ++i) {
        A.at(i - 1).id = i;
        scanf("%d", &A.at(i - 1).ability);
    }
    while (A.size() > 2) {
        vector<Country> A_temp;
        int i = 0;
        int length = static_cast<int>(A.size());
        while (i < length) {
            if (A.at(i).ability > A.at(i + 1).ability) {
                A_temp.emplace_back(A.at(i));
            } else {
                A_temp.emplace_back(A.at(i + 1));
            }
            i += 2;
        }
        A = A_temp;
    }
    if (A.at(0).ability > A.at(1).ability) {
        cout << A.at(1).id;
    } else {
        cout << A.at(0).id;
    }
    cout << '\n';

    return 0;
}