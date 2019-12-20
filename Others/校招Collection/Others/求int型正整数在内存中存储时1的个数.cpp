// https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9

#include <bitset>
#include <iostream>

using namespace std;

int main() {

    int a;
    cin >> a;
    bitset<32> A(a);
    cout << A.count() << endl;

    return 0;
}