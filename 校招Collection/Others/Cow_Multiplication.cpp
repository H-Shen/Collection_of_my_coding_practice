// https://ac.nowcoder.com/acm/contest/997/H

#include <string>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    int sum = 0;
    for (const char &i : A) {
        for (const char &j : B) {
            sum += static_cast<int>(i - '0') * static_cast<int>(j - '0');
        }
    }
    cout << sum << endl;

    return 0;
}