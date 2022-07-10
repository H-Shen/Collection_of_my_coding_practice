constexpr int MAXN = 1005;

class SmallestInfiniteSet {
private:
    set<int> s;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i < MAXN; ++i) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        auto iter = s.begin();
        int temp = *iter;
        s.erase(iter);
        return temp;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */