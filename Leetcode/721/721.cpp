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
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<vector<string> > > unmap, result;
        for (const auto &s : accounts) {
            string name = s.at(0);
            vector<string> mails;
            for (size_t i = 1; i != s.size(); ++i) {
                mails.emplace_back(s.at(i));
            }
            unmap[name].emplace_back(mails);
            result[name].clear();
        }
        for (const auto &[k, v] : unmap) {
            unordered_map<string, int> mail2id;
            unordered_map<int, string> id2mail;
            int id = 0;
            for (const auto &i : v) {
                for (const auto &j : i) {
                    if (mail2id.find(j) == mail2id.end()) {
                        mail2id[j] = id;
                        id2mail[id] = j;
                        ++id;
                    }
                }
            }
            DSU::init(id);
            for (const auto &i : v) {
                if (i.size() > 1) {
                    for (size_t j = 1; j != i.size(); ++j) {
                        DSU::merge(mail2id[i.at(j - 1)], mail2id[i.at(j)]);
                    }
                }
            }
            unordered_map<int, vector<int> > groups;
            for (int i = 0; i < id; ++i) {
                groups[DSU::find(i)].emplace_back(i);
            }
            vector<vector<string> > vec;
            for (const auto &i : groups) {
                vector<string> v(i.second.size());
                for (size_t j = 0; j != i.second.size(); ++j) {
                    v.at(j) = id2mail[i.second.at(j)];
                }
                vec.emplace_back(v);
            }
            result[k] = vec;
        }
        for (auto &[k, v] : result) {
            for (auto &i : v) {
                sort(i.begin(), i.end());
            }
        }
        vector<vector<string> > answer;
        for (const auto &[k, v] : result) {
            for (const auto &i : v) {
                vector<string> vec = {k};
                for (const auto &j : i) {
                    vec.emplace_back(j);
                }
                answer.emplace_back(vec);
            }
        }
        return answer;
    }
};