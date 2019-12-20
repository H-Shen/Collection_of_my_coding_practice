// https://www.nowcoder.com/practice/ca5c9ba9ebac4fd5ae9ba46114b0f476

#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

unordered_set<string> A;
int lenA = 0;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        if (A.find(s) == A.end()) {
            A.insert(s);
            lenA++;
        }
    }

    cout << lenA << endl;
    return 0;
}