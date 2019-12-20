// https://ac.nowcoder.com/acm/problem/14664

#include <bits/stdc++.h>

using namespace std;
vector <int> a(3);

int main()
{
    int n;
    cin >> n;
    while (n--) {
        for (auto &p : a) {
            cin >> p;
        }
        cout << *min_element(a.begin(), a.end()) << endl;
    }
    return 0;
}