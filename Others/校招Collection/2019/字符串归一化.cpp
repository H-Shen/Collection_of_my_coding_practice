// https://www.nowcoder.com/practice/6d5e036defdf408681376a4a9d4930ff
#include <iostream>
#include <string>

using namespace std;
const int MAXN = 26;
int A[MAXN];

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for (const auto &ch : s) {
        ++A[ch - 'a'];
    }
    for (size_t i = 0; i != MAXN; ++i) {
        if (A[i] != 0) {
            cout << static_cast<char>(i + 'a') << A[i];
        }
    }
    cout << endl;

    return 0;
}