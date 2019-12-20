// https://ac.nowcoder.com/acm/problem/14533

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int n;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == "lansou") {
            cout << "xianggu" << endl;
        } else {
            cout << "lansou" << endl;
        }
    }
    return 0;
}