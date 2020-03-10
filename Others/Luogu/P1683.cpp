#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
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
    }
}

int main() {

    int c, r;
    cin >> c >> r;
    string s;
    vector<string> A;
    while (cin >> s) {
        A.emplace_back(s);
    }

    int pos_i = -1;
    int pos_j = -1;
    bool flag = false;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '@') {
                pos_i = i;
                pos_j = j;
                A.at(i).at(j) = '.';
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    if (pos_i == -1 && pos_j == -1) {
        printf("0\n");
        return 0;
    }

    DSU::init(r * c + 5);
    int down;
    int right;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '.') {
                down = i + 1;
                right = j + 1;
                // merge the current pos and the south pos
                if (down < r && A.at(down).at(j) == '.') {
                    DSU::merge(c * i + j, c * down + j);
                }
                // merge the current pos and the east pos
                if (right < c && A.at(i).at(right) == '.') {
                    DSU::merge(c * i + j, c * i + right);
                }
            }
        }
    }
    printf("%d\n", DSU::Size[DSU::find(c * pos_i + pos_j)]);

    return 0;
}
