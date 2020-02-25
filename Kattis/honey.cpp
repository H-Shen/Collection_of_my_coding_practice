// https://open.kattis.com/problems/honey
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// https://oeis.org/A002898
ll A[] = {1,0,6,12,90,360,2040,10080,54810,290640,1588356,
          8676360,47977776,266378112,1488801600};

int main() {

    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        cout << A[val] << '\n';
    }

    return 0;
}
