// https://www.nowcoder.com/practice/0425aa0df74646209d3f56f627298ab2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
    return (stoi(a) < stoi(b));
}

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto &&i : A) {
        cin >> i;
        string temp(i, i.size() - 6);
        i = temp;
    }
    sort(A.begin(), A.end(), cmp);
    for (const auto &i : A) {
        cout << i << endl;
    }
    return 0;
}