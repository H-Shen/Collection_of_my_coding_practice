// https://www.nowcoder.com/practice/daf9032926614dab91ca624a7759a868

#include <iostream>
#include <bitset>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    m ^= n;
    bitset<32> result(m);
    cout << result.count() << endl;

    return 0;
}