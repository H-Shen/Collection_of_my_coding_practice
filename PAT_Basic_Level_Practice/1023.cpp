#include <bits/stdc++.h>

using namespace std;
const int maxn = 10;

int main() {

    vector<int> cnt(maxn);
    int i;
    for (i = 0; i < maxn; ++i) {
        scanf("%d", &cnt[i]);
    }
    string k;
    for (i = 0; i < maxn; ++i) {
        k = k + string(cnt[i], (char) (i + '0'));
    }
    sort(k.begin(), k.end());
    int len = k.size();
    for (i = 0; i < len; ++i) {
        if (k[i] != '0') {
            swap(k[i], k[0]);
            break;
        }
    }
    printf("%s\n", k.c_str());
    return 0;
}