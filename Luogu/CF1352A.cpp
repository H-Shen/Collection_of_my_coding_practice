#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int t, n, counter, temp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        counter = 1;
        vector<int> vec;
        while (n > 0) {
            temp = n % 10;
            if (temp != 0) {
                vec.emplace_back(temp * counter);
            }
            counter *= 10;
            n /= 10;
        }
        cout << vec.size() << '\n';
        bool first_item = true;
        for (const auto &i : vec) {
            if (first_item) {
                first_item = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
    }

    return 0;
}

