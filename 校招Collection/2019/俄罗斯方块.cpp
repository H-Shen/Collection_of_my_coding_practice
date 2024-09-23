// https://www.nowcoder.com/practice/9407e24a70b04fedba4ab3bd3ae29704

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, m, pos;
    cin >> n >> m;
    vector<int> A(n);
    while (m--) {
        cin >> pos;
        ++A[pos - 1];
    }
    cout << *min_element(A.begin(), A.end()) << endl;

    return 0;
}