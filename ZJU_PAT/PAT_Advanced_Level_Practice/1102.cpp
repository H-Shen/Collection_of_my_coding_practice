#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 15;

struct Node {
    int key, left, right;
    Node(int key) : key(key), left(-1), right(-1) {}
    Node() : Node(-1) {}
};

int n;
vector<Node> v;
vector<int> fa;
vector<int> inorder;
vector<vector<int> > levelorder;

void invert(int u) {
    if (u != -1) {
        swap(v[u].left, v[u].right);
        invert(v[u].left);
        invert(v[u].right);
    }
}

void getInorder(int u) {
    if (u != -1) {
        getInorder(v[u].left);
        inorder.emplace_back(u);
        getInorder(v[u].right);
    }
}

int getHeight(int u) {
    if (v[u].left != -1 && v[u].right != -1) {
        return 1+max(getHeight(v[u].left), getHeight(v[u].right));
    }
    else if (v[u].left != -1 && v[u].right == -1) {
        return 1+getHeight(v[u].left);
    }
    else if (v[u].left == -1 && v[u].right != -1) {
        return 1+getHeight(v[u].right);
    }
    return 0;
}

void getLevelOrder(int u) {
    queue<pair<int,int> > q;
    q.push({u,0});
    int currLevel;
    bitset<MAXN> vis;
    while (!q.empty()) {
        u = q.front().first;
        currLevel = q.front().second;
        vis[u] = true;
        q.pop();
        levelorder[currLevel].emplace_back(u);
        if (v[u].left != -1 && !vis[v[u].left]) {
            q.push({v[u].left,currLevel+1});
        }
        if (v[u].right != -1 && !vis[v[u].right]) {
            q.push({v[u].right,currLevel+1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    decltype(v)().swap(v);
    v.resize(n);
    decltype(fa)().swap(fa);
    fa.resize(n, -1);
    decltype(inorder)().swap(inorder);
    decltype(levelorder)().swap(levelorder);
    string s_l, s_r;
    for (int i = 0; i < n; ++i) {
        v[i].key = i;
        cin >> s_l >> s_r;
        if (s_l != "-") {
            v[i].left = stoi(s_l);
            fa[v[i].left] = v[i].key;
        }
        if (s_r != "-") {
            v[i].right = stoi(s_r);
            fa[v[i].right] = v[i].key;
        }
    }
    int root = fa[0];
    while (fa[root] != -1) {
        root = fa[root];
    }
    invert(root);
    getInorder(root);
    levelorder.resize(getHeight(root)+1);
    getLevelOrder(root);
    // output
    bool firstItem = true;
    for (const auto &i : levelorder) {
        if (!i.empty()) {
            for (const auto &j : i) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << ' ';
                }
                cout << j;
            }
        }
    }
    cout << '\n';
    firstItem = true;
    for (const auto &i : inorder) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << '\n';
    return 0;
}
