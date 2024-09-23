// https://www.nowcoder.com/practice/8738b757e0f7469c92cc2585b13a3669

#include <bits/stdc++.h>

using namespace std;

inline
bool allDigits(const string &s) {
    for (const auto &ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    int t;
    string s, head;
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.size() == 11 && allDigits(s)) {
            head = s.substr(0, 3);
            if (head == "133" || head == "153" || head == "180" || head == "181" || head == "189") {
                cout << "China Telecom";
            } else if (head == "130" || head == "131" || head == "155" || head == "185" || head == "186") {
                cout << "China Unicom";
            } else if (head == "135" || head == "136" || head == "150" || head == "182" || head == "188") {
                cout << "China Mobile Communications";
            } else {
                cout << "-1";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}