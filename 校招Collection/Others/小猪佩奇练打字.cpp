// https://ac.nowcoder.com/acm/problem/14708

#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    unordered_map <char, char> A;
    string s;
    char a, b;
    cin >> s;
    int n;
    cin >> n;
    cin.get();

    for (char i = 'a'; i <= 'z'; ++i) {
        A[i] = i;
    }

    while (n--) {
        cin >> a >> b;
        swap(A[a], A[b]);
    }

    for (decltype(s.size()) i = 0; i != s.size(); ++i) {
        if (A.find(s[i]) == A.end()) {
            A[s[i]] = s[i];
            cout << s[i];
        } else {
            cout << A[s[i]];
        }
    }

    cout << endl;
    return 0;
}