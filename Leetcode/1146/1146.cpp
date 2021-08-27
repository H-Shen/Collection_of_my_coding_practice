class SnapshotArray {
private:
    int snap_id;
    vector<vector<pair<int,int> > > v;  // <snap_id, val>
public:
    SnapshotArray(int length) {
        snap_id = -1;
        v.resize(length);
        for (int i = 0; i < length; ++i) {
            v[i].emplace_back(snap_id, 0);
        }
    }
    
    void set(int index, int val) {
        if (!binary_search(v[index].begin(),v[index].end(),make_pair(snap_id, val))) {
            v[index].emplace_back(snap_id, val);
        }
        else {
            size_t pos = lower_bound(v[index].begin(),v[index].end(),make_pair(snap_id,0)) - v[index].begin();
            v[index][pos].second = val;
        }
    }
    
    int snap() {
        ++snap_id;
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        auto iter = --upper_bound(v[index].begin(),v[index].end(),make_pair(snap_id,0));
        return iter->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */