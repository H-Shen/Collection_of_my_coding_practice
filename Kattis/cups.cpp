// https://open.kattis.com/problems/cups

#include<bits/stdc++.h>

using namespace std;
const int maxn = 9;

struct Cup {
    int d;
    string color;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string a, b;
    string color;
    int d;
    cin >> n;

    vector<Cup> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        try {
            d = stoi(a);
            color = b;
        } catch (...) {
            d = stoi(b) * 2;
            color = a;
        }
        A[i].color = color;
        A[i].d = d;
    }

    sort(A.begin(), A.end(), [](const Cup &a, const Cup &b) -> bool {
        return (a.d < b.d);
    });

    for (const auto &i : A) {
        cout << i.color << endl;
    }

    return 0;
}
