#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10;
char name[MAXN];

namespace DSU {
    vector<int> father;
    inline static
    void init(int n) {
        vector<int>().swap(father);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
    }
    inline static
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    // x: father y: son
    inline static
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        father[y] = x;  // combine y to x
    }
}

unordered_map<string, unordered_set<string> > father2sons;
unordered_map<string, int> name_hashmap;
unordered_map<int, string> name_hashmap_rev;
vector<string> query;

int main() {

    string s;
    string father;
    string son;
    while (true) {
        scanf("%s", name);
        if (strcmp(name, "$") == 0) {
            break;
        }
        if (name[0] == '?') {
            s = name;
            s = s.substr(1);
            query.emplace_back(s);
            name_hashmap[s] = 0;
        } else if (name[0] == '#') {
            father = name;
            father = father.substr(1);
            name_hashmap[father] = 0;
        } else {
            son = name;
            son = son.substr(1);
            name_hashmap[son] = 0;
            father2sons[father].insert(son);
        }
    }
    int counter = 1;
    for (auto &[k, v] : name_hashmap) {
        v = counter;
        ++counter;
    }
    for (const auto &[k, v] : name_hashmap) {
        name_hashmap_rev[v] = k;
    }
    DSU::init(counter + 5);
    for (auto &[father, son_list] : father2sons) {
        for (auto &son_name : son_list) {
            DSU::merge(name_hashmap[father], name_hashmap[son_name]);
        }
    }
    // output
    for (const auto &i : query) {
        printf("%s %s\n", i.c_str(), name_hashmap_rev[DSU::find(name_hashmap[i])].c_str());
    }

    return 0;
}
