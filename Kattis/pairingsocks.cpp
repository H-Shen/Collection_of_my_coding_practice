// https://open.kattis.com/problems/pairingsocks
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n *= 2;
    stack<int> A;
    stack<int> B;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input.at(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        A.push(input.at(i));
    }
    int counter = 0;
    while (true) {
        if (A.empty() && !B.empty()) {
            cout << "impossible" << '\n';
            return 0;
        }
        if (A.empty() && B.empty()) {
            break;
        }
        if (B.empty()) {
            ++counter;
            B.push(A.top());
            A.pop();
        } else if (B.top() == A.top()) {
            ++counter;
            B.pop();
            A.pop();
        } else {
            ++counter;
            B.push(A.top());
            A.pop();
        }
    }
    cout << counter << '\n';

    return 0;
}
