// https://open.kattis.com/problems/arraysmoothening
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

#ifndef RunTests
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    int val;
    unordered_map<int,int> freq;
    while (n--) {
        cin >> val;
        ++freq[val];
    }
    priority_queue<int> pq;
    for (const auto &[_,v] : freq) {
        pq.emplace(v);
    }
    for (int i = 0; i < k; ++i) {
        val = pq.top();
        --val;
        pq.pop();
        if (val > 0) {
            pq.emplace(val);
        }
    }
    if (!pq.empty()) {
        cout << pq.top() << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}
#endif
