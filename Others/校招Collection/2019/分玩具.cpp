// https://www.nowcoder.com/practice/a4771283f1c9435d9aeb3045d55dc030

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    int m;
    while (cin >> m) {

        vector<int> A(m);
        int sum = 0;
        for (auto &&i : A) {
            cin >> i;
            sum += i;
        }

        // check if it can be devided equally
        if (sum % m != 0) {
            cout << -1 << endl;
            continue;
        }

        int toysForAPerson = sum / m;
        bool haveAns = true;
        // check if every difference between every entry and sum / m is even
        for (const auto &i : A) {
            if ((i - toysForAPerson) % 2 != 0) {
                cout << -1 << endl;
                haveAns = false;
                break;
            }
        }
        if (!haveAns) {
            continue;
        }

        // calculate the minimum time to move
        int counter = 0;
        for (const auto &i : A) {
            if (i > toysForAPerson) {
                counter += (i - toysForAPerson) / 2;
            }
        }
        cout << counter << endl;
    }

    return 0;
}