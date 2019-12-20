// https://www.nowcoder.com/practice/27c833289e5f4f5e9ba3718ce9136759?tpId=98

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    list<int> A, B;
    string s;

    // get A
    getline(cin, s);
    istringstream ss0(s);
    do {
        int temp;
        ss0 >> temp;
        A.push_back(temp);
    } while (ss0);
    A.pop_back();

    // get B
    getline(cin, s);
    istringstream ss1(s);
    do {
        int temp;
        ss1 >> temp;
        B.push_back(temp);
    } while (ss1);
    B.pop_back();

    // merge
    A.merge(B);

    // output
    bool firstItem = true;
    for (const auto &it : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << it;
    }
    cout << endl;
    return 0;
}