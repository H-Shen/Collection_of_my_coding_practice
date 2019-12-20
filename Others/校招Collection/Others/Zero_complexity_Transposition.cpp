// https://www.nowcoder.com/practice/c54775799f634c72b447ef31eb36e975

#include <stack>
#include <iostream>

using namespace std;
using ll = long long;
stack<ll> A;

int main() {

    int n;
    ll val;
    cin >> n;
    while (n--) {
        cin >> val;
        A.push(val);
    }
    bool firstItem = true;
    while (!A.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << A.top();
        A.pop();
    }
    cout << endl;
    return 0;
}