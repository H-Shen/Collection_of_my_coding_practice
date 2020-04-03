// https://open.kattis.com/problems/thesaurus
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAX_STR_LEN = 1005;
constexpr int MAXN = 20000;
char cstr[MAX_STR_LEN];

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

unordered_map<string, int> unmap;
unordered_map<int, string> unmap_rev;
unordered_map<int, size_t> groups_id_to_minimal_length;
int counter = 0;

int main() {

    DSU::init(MAXN);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> A(n);
    for (auto &i : A) {
        scanf("%s", cstr);
        i = cstr;
        if (unmap.find(i) == unmap.end()) {
            unmap[i] = counter;
            ++counter;
        }
    }
    string a, b;
    while (m--) {
        scanf("%s", cstr);
        a = cstr;
        if (unmap.find(a) == unmap.end()) {
            unmap[a] = counter;
            ++counter;
        }
        scanf("%s", cstr);
        b = cstr;
        if (unmap.find(b) == unmap.end()) {
            unmap[b] = counter;
            ++counter;
        }
        DSU::merge(unmap[a], unmap[b]);
    }
    for (const auto &[k, v] : unmap) {
        unmap_rev[v] = k;
    }

    string element_string;
    int group_id;
    for (int i = 0; i < counter; ++i) {
        element_string = unmap_rev[i];
        group_id = DSU::find(i);
        if (groups_id_to_minimal_length.find(group_id) == groups_id_to_minimal_length.end()) {
            groups_id_to_minimal_length[group_id] = element_string.size();
        } else {
            groups_id_to_minimal_length[group_id] = min(groups_id_to_minimal_length[group_id], element_string.size());
        }
    }

    size_t min_length = 0;
    for (const auto &i : A) {
        min_length += groups_id_to_minimal_length[DSU::find(unmap[i])];
    }
    printf("%zd\n", min_length);

    return 0;
}
