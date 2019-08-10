// https://ac.nowcoder.com/acm/problem/14520

#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    while (n--) {
        cin >> i;
        if (i == 1) {
            cout << "71" << endl;
        } else {
            cout << to_string(i - 1) << "71" << endl;
        }
    }
    return 0;
}