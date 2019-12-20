// https://www.nowcoder.com/practice/bcd4ec5971054997a1dc282067aa1d8b

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {

    size_t m;
    while (cin >> m) {

        vector<ll> result;
        vector<vector<ll> > A(m, vector<ll>(m));
        for (auto &&i : A) {
            for (auto &&j : i) {
                cin >> j;
            }
        }

        // add each rows;
        ll sum;
        for (const auto &i : A) {
            sum = 0;
            for (const auto &j : i) {
                sum += j;
            }
            result.push_back(sum);
        }

        // add each cols
        for (size_t i = 0; i != m; ++i) {
            sum = 0;
            for (size_t j = 0; j != m; ++j) {
                sum += A.at(j).at(i);
            }
            result.push_back(sum);
        }

        // add two diagonals
        sum = 0;
        for (size_t i = 0; i != m; ++i) {
            sum += A.at(i).at(i);
        }
        result.push_back(sum);

        sum = 0;
        for (int i = static_cast<int>(m) - 1; i >= 0; --i) {
            sum += A.at(static_cast<unsigned long>(i)).at(m - 1 - i);
        }
        result.push_back(sum);

        sort(result.begin(), result.end(), greater<>());
        bool firstItem = true;
        for (const auto &i : result) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << " ";
            }
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
