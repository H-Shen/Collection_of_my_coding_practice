// Sqrt Decomp + minHeap

#include <bits/stdc++.h>

using namespace std;

constexpr int BLOCKS = 15;

struct Node {
    string name;
    int age, worth;
    bool operator < (const Node &r) const {
        if (worth == r.worth) {
            if (age == r.age) {
                return name > r.name;
            }
            return age > r.age;
        }
        return worth < r.worth;
    }
};

bool cmp(const Node &l, const Node &r) {
    if (l.worth == r.worth) {
        if (l.age == r.age) {
            return l.name < r.name;
        }
        return l.age < r.age;
    }
    return l.worth > r.worth;
}

int n, m;
int blocks;
vector<vector<Node> > block;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int age, worth;
    string name;
    cin >> n >> m;
    block.resize(BLOCKS+1);
    Node node;
    for (int i = 0; i < n; ++i) {
        cin >> node.name >> node.age >> node.worth;
        int block_id = node.age / BLOCKS + 1;
        block[block_id].emplace_back(node);
    }
    // sort each block 
    for (int i = 1; i <= BLOCKS; ++i) {
        sort(block[i].begin(),block[i].end(),cmp);
    }
    int k, l, r;
    for (int i = 1; i <= m; ++i) {
        cin >> k >> l >> r;
        int left_block_id = l / BLOCKS+1;
        int right_block_id = r / BLOCKS+1;
        set<Node, less<> > s;
        // Case 1: in a single block
        if (left_block_id == right_block_id) {
            for (const auto &j : block[left_block_id]) {
                if (j.age >= l && j.age <= r) {
                    if ((int)s.size() < k) {
                        s.insert(j);
                    }
                    else {
                        if (cmp(j, *s.begin()) > 0) {
                            s.erase(s.begin());
                            s.insert(j);
                        }
                    }
                }
            }
            cout << "Case #" << i << ":\n";
            if (s.empty()) {
                cout << "None" << '\n';
            }
            else {
                for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
                    cout << iter->name << ' ' << iter->age << ' ' << iter->worth << '\n';
                }
            }
        }
        // Case 2: multiple blocks 
        else {
            for (int currblock = left_block_id; currblock <= right_block_id; ++currblock) {
                if (currblock == left_block_id || currblock == right_block_id) {
                    for (const auto &j : block[currblock]) {
                        if (j.age >= l && j.age <= r) {
                            if ((int)s.size() < k) {
                                s.insert(j);
                            }
                            else {
                                if (cmp(j, *s.begin()) > 0) {
                                    s.erase(s.begin());
                                    s.insert(j);
                                }
                            }
                        }
                    }
                }
                else { 
                    int counter = min(k, (int)block[currblock].size());
                    for (int j = 0; j < counter; ++j) {
                        if ((int)s.size() < k) {
                            s.insert(block[currblock][j]);
                        }
                        else {
                            if (cmp(block[currblock][j], *s.begin()) > 0) {
                                s.erase(s.begin());
                                s.insert(block[currblock][j]);
                            }
                        }
                    }
                }
            }
            cout << "Case #" << i << ":\n";
            if (s.empty()) {
                cout << "None" << '\n';
            }
            else {
                for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
                    cout << iter->name << ' ' << iter->age << ' ' << iter->worth << '\n';
                }
            }
        }
    }
    return 0;
}
