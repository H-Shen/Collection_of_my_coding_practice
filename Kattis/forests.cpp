// https://open.kattis.com/problems/forests
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int p, t;
    scanf("%d %d", &p, &t);
    unordered_map<int, vector<int> > A;
    int i, j;
    while (~scanf("%d %d", &i, &j)) {
        A[i].emplace_back(j);
    }
    string s;
    unordered_set<string> temp_unset;
    for (auto &item : A) {
        sort(item.second.begin(), item.second.end());
        s = "";
        for (const auto &element : item.second) {
            s += to_string(element) + " ";
        }
        temp_unset.insert(s);
    }
    for (int people = 1; people <= p; ++people) {
        if (A.find(people) == A.end()) {
            temp_unset.insert("");
        }
    }
    printf("%lu\n", temp_unset.size());

    return 0;
}
