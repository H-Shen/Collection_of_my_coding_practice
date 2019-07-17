#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int query, queryNum, pos;
    cin >> query;
    for (int i = 0; i < query; i++) {
        cin >> queryNum;
        if (binary_search(a.begin(), a.end(), queryNum)) {
            pos = lower_bound(a.begin(), a.end(), queryNum) - a.begin();
            cout << "Yes " << pos + 1 << endl;
        }
        else {
            pos = lower_bound(a.begin(), a.end(), queryNum) - a.begin();
            cout << "No " << pos + 1 << endl;
        }
    }
    return 0;
}
