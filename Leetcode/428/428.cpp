/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
    pair<vector<int>, vector<vector<int> > > parse(const string &s) {
        vector<int> id2val;
        size_t pos = s.find('}');
        id2val = parseVector(s.substr(0, pos+1));
        int n = (int)id2val.size(); 
        vector<vector<int> > AL(n);
        const static regex r(R"(\{[^\{]*\})");
        string str = s.substr(pos+3, s.size()-pos-4);
        vector<int> temp;
        int index = 0;
        for (sregex_iterator a(str.begin(), str.end(), r), e; a != e; ++a) {
            temp = parseVector(a->str());
            if (!temp.empty()) {
                AL[index] = temp;
            }
            ++index;
        }
        return {id2val, AL};
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) {
            return "{},{}";
        }
        unordered_map<Node*, int> unmap;
        int id = 0;
        // bfs1
        queue<Node*> q;
        q.push(root);
        Node* node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            unmap[node] = id;
            ++id;
            for (const auto &i : node->children) {
                q.push(i);
            }
        }
        // bfs2
        int n = (int)unmap.size();
        vector<int> id2val(n);
        queue<Node*>().swap(q);
        q.push(root);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            id2val[unmap[node]] = node->val;
            for (const auto &i : node->children) {
                q.push(i);
            }
        }
        // give root a special flag
        constexpr int INF = 0x3f3f3f3f;
        id2val[unmap[root]] += INF;
        
        // bfs3
        vector<vector<int> > AL(n);
        queue<Node*>().swap(q);
        q.push(root);
        int u, v;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            u = unmap[node];
            for (const auto &i : node->children) {
                v = unmap[i];
                AL[u].emplace_back(v);
                q.push(i);
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
        int length;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans.push_back(',');
            }
            ans.push_back('{');
            if (AL[i].empty()) {
                ans.push_back('}');
            }
            else {
                length = (int)AL[i].size();
                for (int j = 0; j < length; ++j) {
                    if (j > 0) {
                        ans.push_back(',');
                    }
                    ans += to_string(AL[i][j]);
                }
                ans.push_back('}');
            }
        }
        ans.push_back('}');
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        auto p = parse(data);
        auto& id2val = p.first;
        if (id2val.empty()) {
            return nullptr;
        }
        constexpr int INF = 0x3f3f3f3f;
        auto& AL = p.second;
        int n = (int)id2val.size();
        vector<Node*> vec(n, nullptr);
        int rootPos = 0;
        for (int i = 0; i < n; ++i) {
            vec[i] = new Node(id2val[i]);
            if (id2val[i] >= INF) {
                rootPos = i;
                // restore
                vec[i]->val -= INF;
            }
        }
        int length;
        for (int i = 0; i < n; ++i) {
            if (!AL[i].empty()) {
                length = (int)AL[i].size();
                vec[i]->children.resize(length);
                for (int j = 0; j < length; ++j) {
                    vec[i]->children[j] = vec[AL[i][j]];
                }
            }  
        }
        return vec[rootPos];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));