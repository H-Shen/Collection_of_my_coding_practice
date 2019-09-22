// https://open.kattis.com/problems/cardtrick2
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<int, initializer_list<int> > A = {
            {1, {1}},
            {2, {2, 1}},
            {3, {3, 1, 2}},
            {4, {2, 1, 4, 3}},
            {5, {3, 1, 4, 5, 2}},
            {6, {4, 1, 6, 3, 2, 5}},
            { 7, {5, 1, 3, 4, 2, 6, 7}},
            { 8, {3, 1, 7, 5, 2, 6, 8, 4}},
            { 9, {7, 1, 8, 6, 2, 9, 4, 5, 3}},
            { 10, {9, 1, 8, 5, 2, 4, 7, 6, 3, 10}},
            { 11, {5, 1, 6, 4, 2, 10, 11, 7, 3, 8, 9}},
            { 12, {7, 1, 4, 9, 2, 11, 10, 8, 3, 6, 5, 12}},
            { 13, {4, 1, 13, 11, 2, 10, 6, 7, 3, 5, 12, 9, 8}}};

    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        const auto &p = A[val];
        bool firstItem = true;
        for (const auto &i : p) {
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
