#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string stra, strb;
    cin >> stra >> strb;
    unordered_map<char,int> a, b;
    for (const auto &i : stra) {
        ++a[i];
    }
    for (const auto &i : strb) {
        ++b[i];
    }
    bool flag = true;   // Yes
    for (const auto &i : b) {
        if (a.find(i.first) == a.end() || a[i.first] < i.second) {
            flag = false;
            break;
        }
    }
    int counter = 0;
    if (flag) {
        for (const auto &i : a) {
            if (b.find(i.first) == b.end()) {
                counter += i.second;
            }
            else {
                counter += i.second - b[i.first];
            }
        }
        cout << "Yes ";
    }
    else {
        for (const auto &i : b) {
            if (a.find(i.first) == a.end()) {
                counter += i.second;
            }
            else {
                if (a[i.first] < i.second) {
                    counter += i.second - a[i.first];
                }
            }
        }
        cout << "No ";
    }
    cout << counter << '\n';
    return 0;
}
