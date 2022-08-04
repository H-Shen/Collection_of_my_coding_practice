// https://open.kattis.com/problems/99problems

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 100;
const string NN = "99";

vector<int> vec;

int main(){
    vec.emplace_back(99);
    for (int i = 1; i <= MAXN; ++i) {
        vec.emplace_back(stoi(to_string(i) + NN));
    }
    int n;
    cin >> n;
    auto iter = lower_bound(vec.begin(), vec.end(), n);
    if (iter == vec.end()) {
        cout << vec.back() << '\n';
        return 0;
    }
    int index = (int)(iter - vec.begin());
    if (index == 0) {
        cout << vec[0] << '\n';
        return 0;
    }
    int diff1 = abs(vec[index] - n);
    int diff2 = abs(vec[index-1] - n);
    if (diff1 > diff2) {
        cout << vec[index-1] << '\n';
    }
    else {
        cout << vec[index] << '\n';
    }
    return 0;
}
