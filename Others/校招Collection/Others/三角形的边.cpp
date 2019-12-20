// https://www.nowcoder.com/practice/05dbd1cd43b24dbbae567b3e816d4e97

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 3;
int A[MAXN];

int main() {

    while (cin >> A[0] >> A[1] >> A[2]) {
        sort(A, A + MAXN);
        cout << A[0] + A[1] - A[2] << endl;
    }

    return 0;
}