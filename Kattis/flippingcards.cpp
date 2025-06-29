#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        cc = n;
    }
    int find(int x) {
        return father[x] == x ? x : (father[x] = find(father[x]));
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        --cc;
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
    int check_set_size(int x) {
        return Size[find(x)];
    }
    int number_of_disjoint_sets() {
        return cc;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<pair<int,int>> card(n);
        vector<int> all;
        all.reserve(2*n);

        for(int i = 0; i < n; i++){
            cin >> card[i].first >> card[i].second;
            all.push_back(card[i].first);
            all.push_back(card[i].second);
        }

        // compress picture IDs to [0..m-1]
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int m = all.size();

        // initialize DSU with n cards + m pictures
        DSU::init(n + m);

        // union each card i with its two picture‐nodes
        for(int i = 0; i < n; i++){
            int p = (int)(lower_bound(all.begin(), all.end(), card[i].first)  - all.begin());
            int q = (int)(lower_bound(all.begin(), all.end(), card[i].second) - all.begin());
            DSU::merge(i, n + p);
            DSU::merge(i, n + q);
        }

        // count cards vs. distinct pictures in each component
        vector<int> cntL(n + m, 0), cntR(n + m, 0);
        for(int i = 0; i < n; i++){
            int r = DSU::find(i);
            ++cntL[r];
        }
        for(int j = 0; j < m; j++){
            int r = DSU::find(n + j);
            ++cntR[r];
        }

        // check Hall's condition in each component
        bool ok = true;
        for(int x = 0; x < n + m; x++){
            if(DSU::find(x) == x && cntL[x] > cntR[x]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "possible\n" : "impossible\n");
    }

    return 0;
}
