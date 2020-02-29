// https://www.nowcoder.com/practice/c747216a5db24df385392f1a6b90a084

#include <bits/stdc++.h>

using namespace std;
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

vector<ll> parse(const string &s) {
    istringstream iss(s);
    string temp;
    vector<ll> result;
    do {
        iss >> temp;
        result.emplace_back(stoll(temp));
    } while (iss);
    result.pop_back();
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    unordered_map<ll, int> elements2index;
    vector<vector<ll> > input;
    int counter = 1;
    int min_val = 1;
    int max_val = 1;

    int n;
    cin >> n;
    cin.get();
    while (n--) {
        getline(cin, s);
        input.emplace_back(parse(s));
    }
    for (const auto &i : input) {
        for (const auto &j : i) {
            if (elements2index.find(j) == elements2index.end()) {
                elements2index[j] = counter;
                max_val = max(max_val, counter);
                ++counter;
            }
        }
    }
    DSU::init(counter);
    for (const auto &i : input) {
        if (i.size() > 1) {
            for (size_t j = 1; j != i.size(); ++j) {
                DSU::merge(elements2index[i.at(j)], elements2index[i.at(j - 1)]);
            }
        }
    }

    unordered_set<int> roots_of_groups;
    int max_elements = -1;
    int root;
    for (int i = min_val; i <= max_val; ++i) {
        root = DSU::find(i);
        roots_of_groups.insert(root);
        max_elements = max(max_elements, DSU::Size[root]);
    }
    cout << roots_of_groups.size() << '\n';
    cout << max_elements << '\n';
    return 0;
}