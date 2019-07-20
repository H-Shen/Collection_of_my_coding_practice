// https://www.nowcoder.com/practice/16e48900851646c0b2c6cdef9d7ea051

#include <bitset>
#include <iostream>

using namespace std;

int main() {

    unsigned long long a, b;
    cin >> a >> b;
    bitset<64> result(a ^ b);
    cout << result.count() << endl;

    return 0;
}