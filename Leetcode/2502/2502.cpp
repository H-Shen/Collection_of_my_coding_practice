constexpr int MAXN = 1005;

class Allocator {
private:
    bitset<MAXN> bs;
    unordered_map<int, vector<pair<int,int>>> unmap;
    int n;
public:
    Allocator(int n) {
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        int l, r;
        for (int i = 0; i < n; ++i) {
            if (!bs[i]) {
                ++cnt;
                if (cnt == size) {
                    r = i;
                    l = i - size + 1;
                    // process here
                    for (int j = l; j <= r; ++j) {
                        bs[j] = true;
                    }
                    unmap[mID].emplace_back(l,r);
                    return l;
                }
            } else {
                cnt = 0;
            }
        }
        if (cnt == size) {
            r = n-1;
            l = n-1 - size + 1;
            // process here
            for (int j = l; j <= r; ++j) {
                bs[j] = true;
            }
            unmap[mID].emplace_back(l,r);
            return l;
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        if (unmap.count(mID) > 0) {
            int l, r;
            for (auto&i : unmap[mID]) {
                l = i.first;
                r = i.second;
                for (int j = l; j <= r; ++j) {
                    bs[j] = false;
                    ++cnt;
                }
            }
            unmap.erase(mID);
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */