class OrderedStream {
public:
    int n, index;
    vector<string> vec;
    vector<bool> vis;
    OrderedStream(int n) : n(n), index(1) {
        vis.resize(n+1, false);
        vec.resize(n+1);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> result;
        vis[idKey] = true;
        vec[idKey] = value;
        if (index != idKey) {
            return result;
        }
        int i;
        for (i = idKey; i <= n; ++i) {
            if (!vis[i]) {
                break;
            }
            result.emplace_back(vec[i]);
        }
        index = i;
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */