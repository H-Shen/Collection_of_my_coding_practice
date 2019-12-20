// https://www.nowcoder.com/practice/43d22dbc8bef46529e722dc6a5fb1e2d

#include <iostream>
#include <bitset>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int s;
    cin >> s;
    bitset<32> n(s);
    cout << n.count() << endl;

    return 0;
}