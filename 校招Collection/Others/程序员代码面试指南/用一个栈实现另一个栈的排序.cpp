// https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    stack<int> start;
    stack<int> helper;
    int n, val;

    cin >> n;
    while (n--) {
        cin >> val;
        start.push(val);
    }
    while (!start.empty()) {
        val = start.top();
        start.pop();
        while (!helper.empty() && val > helper.top()) {
            start.push(helper.top());
            helper.pop();
        }
        helper.push(val);
    }
    while (!helper.empty()) {
        start.push(helper.top());
        helper.pop();
    }
    // output
    bool firstItem = true;
    while (!start.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << start.top();
        start.pop();
    }
    cout << endl;
    return 0;
}