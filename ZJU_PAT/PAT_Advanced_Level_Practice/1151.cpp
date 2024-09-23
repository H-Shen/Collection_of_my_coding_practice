#include <bits/stdc++.h>

using namespace std;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
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
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x,y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

namespace LCA {
    int n, l;
    vector<vector<int> > AL;
    int timer;
    vector<int> dfs_in, dfs_out;
    vector<vector<int> > up;
    void pre(int n_) {
        n = n_;
        decltype(AL)().swap(AL);
        decltype(up)().swap(up);
        vector<int>().swap(dfs_in);
        vector<int>().swap(dfs_out);
        
        timer = 0;
        AL.resize(n);
        dfs_in.resize(n);
        dfs_out.resize(n);
        l = ceil(log2(n * 1.0));
        up.resize(n, vector<int>(l+1));
    }
    void dfs(int v, int p) {
        dfs_in[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (const auto &u : AL[v]) {
            if (u != p) {
                dfs(u, v);
            }
        }
        dfs_out[v] = ++timer;
    }
    bool isancestor(int u, int v) {
        return dfs_in[u] <= dfs_in[v] && dfs_out[u] >= dfs_out[v];
    }
    int lca(int u, int v) {
        if (isancestor(u,v)) return u;
        if (isancestor(v,u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!isancestor(up[u][i],v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
}

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};
int n;
vector<int> preorder;
vector<int> inorder;
unordered_map<int,int> val2pos;

Node* dfs(int preorder_l, int preorder_r, int inorder_l, int inorder_r) {
    if (preorder_l > preorder_r) {
        return nullptr;
    }
    int root_val = preorder[preorder_l];
    int root_index = val2pos[root_val];
    Node* root = new Node(root_val);
    int size_left_subtree = root_index - inorder_l;
    root->left = dfs(preorder_l+1,preorder_l+size_left_subtree,inorder_l,root_index-1);
    root->right = dfs(preorder_l+size_left_subtree+1,preorder_r,root_index+1,inorder_r);
    return root;
}

Node* buildTree() {
    for (int i = 0; i < n; ++i) {
        val2pos[inorder[i]] = i;
    }
    return dfs(0,n-1,0,n-1);
}

void Dfs(Node* u, Node* fa) {
    if (u) {
        if (fa) {
            int u_index = val2pos[u->val];
            int fa_index = val2pos[fa->val];
            LCA::AL[u_index].emplace_back(fa_index);
            LCA::AL[fa_index].emplace_back(u_index);
        }
        Dfs(u->left, u);
        Dfs(u->right, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m >> n;
    decltype(preorder)().swap(preorder);
    decltype(inorder)().swap(inorder);
    val2pos.clear();
    inorder.resize(n);
    preorder.resize(n);
    LCA::pre(n);
    for (auto &i : inorder) {
        cin >> i;
    }
    for (auto &i : preorder) {
        cin >> i;
    }
    Node* bTree = buildTree();
    Dfs(bTree, nullptr);
    LCA::dfs(val2pos[bTree->val], val2pos[bTree->val]);
    int u, v, i, j;
    while (m--) {
        cin >> i >> j;
        vector<int> temp;
        if (val2pos.find(i) == val2pos.end()) {
            temp.emplace_back(i);
        }
        if (val2pos.find(j) == val2pos.end()) {
            temp.emplace_back(j);
        }
        if (temp.size() == 1) {
            cout << "ERROR: " << temp.front() << " is not found." << '\n';
        }
        else if (temp.size() == 2) {
            cout << "ERROR: " << temp.front() << " and " << temp.back() << " are not found." << '\n';
        }
        else {
            u = val2pos[i];
            v = val2pos[j];
            int getlca = LCA::lca(u,v);
            if (getlca == u) {
                cout << i << " is an ancestor of " << j << ".\n"; 
            }
            else if (getlca == v) {
                cout << j << " is an ancestor of " << i << ".\n"; 
            }
            else {
                cout << "LCA of " << i << " and " << j << " is " << inorder[getlca] << ".\n";
            }
        }
    }
    return 0;
}
