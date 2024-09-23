// https://www.nowcoder.com/practice/743de16bf29041b7b423609628a1fa8c

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main() {

    vector<ull> A = {0, 1};

    while (true) {
        A.emplace_back(A.at(A.size() - 1) + A.at(A.size() - 2));
        if (A.at(A.size() - 1) < A.at(A.size() - 2)) {
            A.pop_back();
            break;
        }
    }

    ull n;
    cin >> n;
    ull gap;
    if (binary_search(A.begin(), A.end(), n)) {
        gap = 0;
    } else if (n > A.back()) {
        gap = n - A.back();
    } else {
        size_t upperIndex = upper_bound(A.begin(), A.end(), n) - A.begin();
        gap = min(n - A.at(upperIndex - 1), A.at(upperIndex) - n);
    }
    cout << gap << endl;

    return 0;
}