#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 15;
constexpr int MAX_STICKS = 500005;
char a[MAXN];
char b[MAXN];

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
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

unordered_map<string, int> string2id;
vector<int> degrees(MAX_STICKS);
int id = 0;

// 1. We must make sure that the graph is consist of at most 1 connected component
// 2. We must make sure that the graph is a Eulerian path: that is,
//    it is necessary that 0 or 2 vertices have an odd degree
// 3. The existence of a Eulerian cycle is not necessary.

// A counterexample that the condition 2 is not satisfied:
//
//         3
//       /
//    1-2
//       \
//         4

int main() {

    DSU::init(MAX_STICKS);
    string a_str, b_str;
    while (~scanf("%s %s", a, b)) {
        a_str = a;
        b_str = b;
        if (string2id.find(a_str) == string2id.end()) {
            string2id[a_str] = id;
            ++id;
        }
        if (string2id.find(b_str) == string2id.end()) {
            string2id[b_str] = id;
            ++id;
        }
        DSU::merge(string2id[a_str], string2id[b_str]);
        ++degrees.at(string2id[a_str]);
        ++degrees.at(string2id[b_str]);
    }
    unordered_set<int> groups;
    for (int i = 0; i < id; ++i) {
        groups.insert(DSU::find(i));
        if (groups.size() > 1) {    // more than 1 connected component
            printf("Impossible\n");
            return 0;
        }
    }
    int counter = 0;
    for (int i = 0; i < id; ++i) {
        if (degrees.at(i) & 1) {
            ++counter;
        }
    }
    if (counter == 0 || counter == 2) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }

    return 0;
}