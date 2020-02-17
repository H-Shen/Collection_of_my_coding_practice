#include <bits/stdc++.h>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string s;
    int val;
    unordered_map<string, int> a;
    for (int i = 0; i < n; ++i) {
        cin >> s >> val;
        a[s] = val;
    }
    string query;
    while (cin >> query) {
        if (a.find(query) != a.end()) {
            cout << query << '=' << a[query] << endl;
        } else {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
