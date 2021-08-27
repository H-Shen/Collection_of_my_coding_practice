/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> v;
public:
    int getHeight(TreeNode* root) {
        if (root->left && root->right) {
            return 1+max(getHeight(root->left), getHeight(root->right));
        }
        else if (root->left && !root->right) {
            return 1+getHeight(root->left);
        }
        else if (!root->left && root->right) {
            return 1+getHeight(root->right);
        }
        return 1;
    }
    CBTInserter(TreeNode* root) {
        // bfs
        if (root) {
            // get height
            int height = getHeight(root);
            vector<vector<TreeNode*>> vec(height);
            queue<pair<TreeNode*,int> > q;
            q.push({root,0});
            while (!q.empty()) {
                auto node = q.front().first;
                int level = q.front().second;
                vec[level].emplace_back(node);
                q.pop();
                if (node->left) {
                    q.push({node->left,level+1});
                }
                if (node->right) {
                    q.push({node->right,level+1});
                }
            }
            v.emplace_back(nullptr);    // fake node in the first slot
            for (const auto &i : vec) {
                for (const auto &j : i) {
                    v.emplace_back(j);
                }
            }
        }
    }
    
    int insert(int val) {
        auto node = new TreeNode(val);
        v.emplace_back(node);
        int id = (int)v.size()-1;
        if (id & 1) {
            v[id / 2]->right = node;
        } else {
            v[id / 2]->left = node;
        }
        return v[id / 2]->val;
    }
    
    TreeNode* get_root() {
        return v[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */