namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    vector<vector<int> > vec;
    void dfs(int pos, vector<int> path, vector<string> &ans, const vector<string> &id2node) {
        if (pos >= (int)vec.size()) {
            string str;
            bool firstItem = true;
            for (const auto &i : path) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    str.push_back(' ');
                }
                str += id2node[i];
            }
            ans.emplace_back(str);
            return;
        }
        for (const auto &i : vec[pos]) {
            vector<int> pathCopy(path);
            pathCopy.emplace_back(i);
            dfs(pos+1, pathCopy, ans, id2node);
        }
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        int id = 0;
        unordered_map<string,int> node2id;
        vector<string> id2node;
        for (const auto &i : synonyms) {
            for (const auto &j : i) {
                if (node2id.find(j) == node2id.end()) {
                    node2id[j] = id;
                    ++id;
                    id2node.emplace_back(j);
                }
            }
        }
        vector<string> v;
        istringstream iss(text);
        string s;
        do {
            iss >> s;
            v.emplace_back(s);
        } while (iss);
        v.pop_back();
        for (const auto &i : v) {
            if (node2id.find(i) == node2id.end()) {
                node2id[i] = id;
                ++id;
                id2node.emplace_back(i);
            }
        }
        DSU::init(id);
        for (const auto &i : synonyms) {
            DSU::merge(node2id[i[0]],node2id[i[1]]);
        }
        vector<string> ans;
        decltype(vec)().swap(vec);
        unordered_map<int, vector<int> > groups;
        for (int i = 0; i < id; ++i) {
            groups[DSU::find(i)].emplace_back(i);
        }
        for (const auto &i : v) {
            vec.emplace_back(groups[DSU::find(node2id[i])]);
        }
        dfs(0, vector<int>(), ans, id2node);
        sort(ans.begin(), ans.end());
        return ans;
    }
};