// https://www.nowcoder.com/practice/bc4c7936f5ed42cbb9131b6f39aa272b

#include <iostream>
#include <bitset>

using namespace std;

int main() {
    long long n;
    cin >> n;
    bitset<128> a(n);
    cout << a.count() << endl;
    return 0;
}