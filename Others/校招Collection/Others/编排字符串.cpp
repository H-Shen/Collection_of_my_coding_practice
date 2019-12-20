// https://www.nowcoder.com/practice/42c0673f04b34f66ae236a1cb7995532

#include <deque>
#include <string>
#include <iostream>

using namespace std;
const int MAXN = 4 + 1;

int main() {

    int n, counter;
    bool firstItem;
    string s;

    while (cin >> n) {

        deque<string> A;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            A.push_front(s);

            // display
            counter = 1;
            firstItem = true;
            for (const auto &str : A) {
                if (counter == MAXN) {
                    continue;
                }
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << " ";
                }
                cout << counter << "=" << str;
                ++counter;
            }
            cout << endl;
        }
    }

    return 0;
}