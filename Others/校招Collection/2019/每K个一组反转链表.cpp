// https://www.nowcoder.com/practice/a632ec91a4524773b8af8694a51109e7

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    vector<int> A;
    string s, temp;
    getline(cin, s);
    istringstream f(s);
    while (getline(f, temp, ' ')) {
        A.emplace_back(stoi(temp));
    }
    int k;
    cin >> k;
    int length = static_cast<int>(A.size());
    int counter = 0;

    if (k > 1 && k <= length) {
        if (k == length) {
            reverse(A.begin(), A.end());
        } else {
            auto it = A.begin();
            while (true) {
                counter += k;
                if (counter > length) {
                    break;
                }
                reverse(it, it + k);
                advance(it, k);
            }
        }
    }

    bool firstItem = true;
    for (const int &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << i;
    }

    return 0;
}