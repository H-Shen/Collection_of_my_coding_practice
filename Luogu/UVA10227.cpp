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

pair<int, int> parse(const string &s) {
    pair<int, int> result;
    stringstream ss(s);
    string a, b;
    ss >> a >> b;
    result.first = stoi(a);
    result.second = stoi(b);
    return result;
}

constexpr int PEOPLE = 105;

int solve(const vector<pair<int, int> > &a, const int &people) {
    unordered_map<int, vector<int> > A;
    for (const auto &i : a) {
        A[i.first].emplace_back(i.second);
    }
    // no opinions is also an opinion
    for (int i = 1; i <= people; ++i) {
        if (A.find(i) == A.end()) {
            A[i] = vector<int>();
        }
    }
    for (auto &i : A) {
        sort(i.second.begin(), i.second.end());
        auto iter = unique(i.second.begin(), i.second.end());
        i.second.erase(iter, i.second.end());
    }
    DSU::init(people);
    for (const auto &i : A) {
        for (const auto &j : A) {
            if (i.first != j.first && i.second == j.second) {
                DSU::merge(i.first, j.first);
            }
        }
    }
    bitset<PEOPLE> groups;
    for (int i = 1; i <= people; ++i) {
        groups[DSU::find(i)] = true;
    }
    return groups.count();
}

int main() {
    int kase, people, tree;
    cin >> kase;
    string s;
    while (kase--) {
        cin >> people >> tree;
        cin.get();
        vector<pair<int, int> > a;
        while (true) {
            if (getline(cin, s) && !s.empty()) {
                a.emplace_back(parse(s));   
            } else {
                break;
            }
        }
        cout << solve(a, people) << '\n';
        if (kase) cout << '\n';
    }
    return 0;
}