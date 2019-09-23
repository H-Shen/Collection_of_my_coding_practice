// https://open.kattis.com/problems/bst
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<int, ll> nodeToDepth;

int main() {

    int n, root, val;
    scanf("%d %d", &n, &root);
    ll counter = 0;
    ll depth;
    int minVal = root;
    int maxVal = root;
    nodeToDepth[root] = counter;
    n--;

    printf("%lld\n", counter);

    while (n--) {
        scanf("%d", &val);
        if (val < minVal) {
            depth = nodeToDepth.begin()->second + 1;
            minVal = val;
        } else if (val > maxVal) {
            depth = nodeToDepth.rbegin()->second + 1;
            maxVal = val;
        } else {
            auto it = nodeToDepth.lower_bound(val);
            auto rightBound = it->second;
            auto leftBound = (--it)->second;
            depth = max(leftBound, rightBound) + 1;
        }
        counter += depth;
        nodeToDepth[val] = depth;
        // output
        printf("%lld\n", counter);
    }

    return 0;
}
