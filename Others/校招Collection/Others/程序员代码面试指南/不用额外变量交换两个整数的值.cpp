// https://www.nowcoder.com/practice/1827258942284b2abfe65809785ac91a

#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    n += m;
    m = n - m;
    n -= m;
    cout << n << ' ' << m << endl;

    return 0;
}