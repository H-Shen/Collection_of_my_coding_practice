// https://ac.nowcoder.com/acm/problem/14543

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int sum = 0;
    while (n--) {
        sum = 0;
        cin >> s;
        for (const auto &p : s) {
            sum += static_cast<int>(p - 'A' + 1);
        }
        cout << sum << endl;
    }
    return 0;
}