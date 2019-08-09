// https://ac.nowcoder.com/acm/problem/14568

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, tmp, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue <int, vector <int>, greater<int> > A;
        while (n--) {
            cin >> tmp;
            A.push(tmp);
        }
        a = A.top();
        A.pop();
        b = A.top();
        cout << a + b << endl;
    }

    return 0;
}