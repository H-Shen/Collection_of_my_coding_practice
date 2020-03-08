// https://open.kattis.com/problems/10kindsofpeople
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
        Size[x] += Size[y];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace DSU_Copy {
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
        Size[x] += Size[y];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

vector<vector<char> > A;

int main() {

    int r, c;
    scanf("%d %d", &r, &c);
    A.resize(r, vector<char>(c));
    getchar();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%c", &A.at(i).at(j));
        }
        getchar();
    }

    DSU::init(r * c);   // to calculate '1'
    DSU_Copy::init(r * c);  // to calculate '0'
    int down;
    int right;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '1') {
                down = i + 1;
                right = j + 1;
                // merge the current pos and the south pos
                if (down < r && A.at(down).at(j) == '1') {
                    DSU::merge(c * i + j, c * down + j);
                }
                // merge the current pos and the east pos
                if (right < c && A.at(i).at(right) == '1') {
                    DSU::merge(c * i + j, c * i + right);
                }
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '0') {
                down = i + 1;
                right = j + 1;
                // merge the current pos and the south pos
                if (down < r && A.at(down).at(j) == '0') {
                    DSU_Copy::merge(c * i + j, c * down + j);
                }
                // merge the current pos and the east pos
                if (right < c && A.at(i).at(right) == '0') {
                    DSU_Copy::merge(c * i + j, c * i + right);
                }
            }
        }
    }

    int query, r1, c1, r2, c2;
    scanf("%d", &query);
    while (query--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        --r1;
        --c1;
        --r2;
        --c2;
        if (A.at(r1).at(c1) != A.at(r2).at(c2)) {
            printf("neither\n");
        }
        else if (A.at(r1).at(c1) == '1') {
            if (DSU::is_same_group(c * r1 + c1, c * r2 + c2)) {
                printf("decimal\n");
            } else {
                printf("neither\n");
            }
        }
        else {
            if (DSU_Copy::is_same_group(c * r1 + c1, c * r2 + c2)) {
                printf("binary\n");
            } else {
                printf("neither\n");
            }
        }
    }

    return 0;
}
