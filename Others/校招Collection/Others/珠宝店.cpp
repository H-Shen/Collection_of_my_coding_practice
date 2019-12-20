// https://ac.nowcoder.com/acm/problem/14347

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, price;
    cin >> t;
    string s;

    while (t--) {
        price = 0;
        cin >> s;
        for (const auto &p : s) {
            price += static_cast<int>(p - 'A' + 1);
        }
        cout << price << endl;
    }

    return 0;
}