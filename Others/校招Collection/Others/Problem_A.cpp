// https://www.nowcoder.com/practice/ee083fda4b39446d9aa543b1039475b8

#include <iostream>
#include <algorithm>

using namespace std;

const int A[] = {6, 28, 496, 8128};

int main() {

    ios_base::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b) {
        for (const int &i : A) {
            if (i >= a && i <= b) {
                cout << i << endl;
            }
        }
    }
    return 0;
}