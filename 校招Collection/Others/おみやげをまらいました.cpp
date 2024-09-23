// https://ac.nowcoder.com/acm/problem/15236

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string a, b, c;
    unordered_map <string, string> A;
    int i;
    for (i = 0; i < 3; ++i) {
        cin >> a >> b;
        A[b] = a;
    }
    int n;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> c;
        if (A.find(c) == A.end()) {
            cout << "Fake" << endl;
        } else {
            cout << A[c] << endl;
        }
    }
    return 0;
}