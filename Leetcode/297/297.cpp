/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<int> parseVector(const string &s) {
        istringstream iss(s.substr(1, s.size() - 2));
        string str;
        vector<int> vec;
        while (getline(iss, str, ',')) {
            vec.emplace_back(stoi(str));
        }
        return vec;
    }
    vector<vector<int> > parse(const string &s) {
        vector<vector<int> > ans(3);
        const static regex r(R"(\{[^\{]*\})");
        int index = 0;
        for (sregex_iterator a(s.begin(),s.end(),r), e; a != e; ++a) {
            ans[index++] = parseVector(a->str());
        }
        return ans;
    }
    // Encodes a tree to a single string.
    // {id2val, left, right}
    string serialize(TreeNode* root) {
        if (!root) {
            return "{},{},{}";
        }
        unordered_map<TreeNode*, int> unmap;
        int id = 0;
        // bfs1
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            unmap[node] = id;
            ++id;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        // bfs2
        int n = (int)unmap.size();
        vector<int> id2val(n);
        queue<TreeNode*>().swap(q);
        q.push(root);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            id2val[unmap[node]] = node->val;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        // give root a special flag
        constexpr int INF = 0x3f3f3f3f;
        id2val[unmap[root]] += INF;
        
        // bfs3
        // -1 means it doesnt have such son
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        queue<TreeNode*>().swap(q);
        q.push(root);
        int u, v;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            u = unmap[node];
            if (node->left) {
                v = unmap[node->left];
                left[u] = v;
                q.push(node->left);
            }
            if (node->right) {
                v = unmap[node->right];
                right[u] = v;
                q.push(node->right);
            }
        }
        string ans;
        ans.push_back('{');
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans.push_back(',');
            }
            ans += to_string(id2val[i]);
        }
        ans.push_back('}');
        ans.push_back(',');
        ans.push_back('{');
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans.push_back(',');
            }
            ans += to_string(left[i]);
        }
        ans.push_back('}');
        ans.push_back(',');
        ans.push_back('{');
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans.push_back(',');
            }
            ans += to_string(right[i]);
        }
        ans.push_back('}');
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto p = parse(data);
        auto& id2val = p[0];
        if (id2val.empty()) {
            return nullptr;
        }
        auto& left = p[1];
        auto& right = p[2];
        int n = (int)id2val.size();
        vector<TreeNode*> vec(n);
        int rootPos = 0;
        constexpr int INF = 0x3f3f3f3f;
        constexpr int MINVAL = -1000;
        for (int i = 0; i < n; ++i) {
            vec[i] = new TreeNode(id2val[i]);
            if (id2val[i] >= INF + MINVAL) {
                rootPos = i;
                vec[i]->val -= INF;
            } 
        }
        for (int i = 0; i < n; ++i) {
            if (left[i] != -1) {
                vec[i]->left = vec[left[i]];
            }
            if (right[i] != -1) {
                vec[i]->right = vec[right[i]];
            }
        }
        return vec[rootPos];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));