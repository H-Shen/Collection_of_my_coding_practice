#include <bits/stdc++.h>

using namespace std;

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
        if (x == y) return;
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

const regex r("[A-Z]");

vector<string> split(const string &s) {
    vector<string> result;
    for (sregex_iterator a(s.begin(), s.end(), r), e; a != e; ++a) {
        result.emplace_back(a->str());
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string s;
    int counter;
    cin >> n;
    int tree, acorn;
    while (n--) {
        counter = 0;
        tree = 0;
        acorn = 0;
        vector<string> input;
        while (true) {
            cin >> s;
            if (s.front() != '*') {
                input.emplace_back(s);
            } else {
                break;
            }
        }
        cin >> s;
        vector<string> nodes = split(s);
        unordered_map<char, int> unmap;
        for (const auto &i : nodes) {
            unmap[i.front()] = counter;
            ++counter;
        }
        DSU::init(counter);
        // add edges
        for (const auto &i : input) {
            DSU::merge(unmap[i.at(1)], unmap[i.at(3)]);
        }
        unordered_map<int, int> groups;
        for (const auto &i : unmap) {
            ++groups[DSU::find(i.second)];
        }
        for (const auto &i : groups) {
            if (i.second == 1) {
                ++acorn;
            } else {
                ++tree;
            }
        }
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)."
             << '\n';
    }
    return 0;
}