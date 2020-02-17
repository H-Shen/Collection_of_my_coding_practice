#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    bitset<32> A(n);
    string s = A.to_string();
    int result = -1;
    int counter = 0;
    bool is_one = false;
    for (const char &ch : s) {
        if (is_one) {
            if (ch == '1') {
                ++counter;
            } else {
                result = max(result, counter);
                counter = 0;
                is_one = false;
            }
        } else {
            if (ch == '1') {
                ++counter;
                is_one = true;
            }
        }
    }
    result = max(result, counter);
    return result;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << solve(n) << endl;

    return 0;
}
