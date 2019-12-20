// https://www.nowcoder.com/practice/9240357eefcf4d938b90bdd5eec3712b

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 26;

int main() {

    ios_base::sync_with_stdio(false);
    vector<char> A(maxn);
    string s;
    cin >> s;
    for (const auto &ch : s) {
        ++A[ch - 'a'];
    }
    int k;
    cin >> k;

    while (k--) {
        size_t pos = max_element(A.begin(), A.end()) - A.begin();
        if (A[pos] > 0) {
            --A[pos];
        }
    }

    long long result = 0;
    for (const auto &i : A) {
        result = result + static_cast<long long>(i) * static_cast<long long>(i);
    }
    cout << result << endl;

    return 0;
}