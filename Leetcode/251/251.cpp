class Vector2D {
private:
    vector<int> v;
    vector<int>::iterator it;
public:
    Vector2D(vector<vector<int>>& vec) {
        for (const auto &i : vec) {
            for (const auto &j : i) {
                v.emplace_back(j);
            }
        }
        if (!v.empty()) {
            it = --v.begin();
        }
    }
    
    int next() {
        ++it;
        return *it;
    }
    
    bool hasNext() {
        if (v.empty()) {
            return false;
        }
        return ::next(it) != v.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */