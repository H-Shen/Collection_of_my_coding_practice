#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    vector<ll> sum_of_elements;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        vector<ll>().swap(sum_of_elements);
        father.resize(2 * n + 5);
        sum_of_elements.resize(2 * n + 5);
        Size.resize(2 * n + 5);
        for (int i = 1; i <= n; ++i) {
            father.at(i) = i + n;
            father.at(i + n) = father.at(i);
            sum_of_elements.at(i + n) = i;
            Size.at(i + n) = 1;
        }
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        sum_of_elements[y] += sum_of_elements[x];
    }
    void move_to(int x_, int y_) {
        int x = find(x_);
        int y = find(y_);
        if (x == y) {
            return;
        }
        --Size[x];
        ++Size[y];
        father[x_] = y;
        sum_of_elements[x] -= x_;
        sum_of_elements[y] += x_;
    }
}


int main() {

    fast_io();
    int n, m, type, p, q, group_id;
    while (cin >> n >> m) {
        DSU::init(n);
        while (m--) {
            cin >> type;
            switch (type) {
                case 1:
                    cin >> p >> q;
                    DSU::merge(p, q);
                    break;
                case 2:
                    cin >> p >> q;
                    DSU::move_to(p, q);
                    break;
                default:
                    cin >> p;
                    group_id = DSU::find(p);
                    cout << DSU::Size[group_id] << ' ' << DSU::sum_of_elements[group_id] << '\n';
                    break;
            }
        }
    }
    return 0;
}