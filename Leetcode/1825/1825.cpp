class MKAverage {
private:
    struct Node {
        int val, id;
        Node(int val, int id) : val(val), id(id) {}
        Node() = default;
        bool operator < (const Node &o) const {
            if (val == o.val) {
                return id < o.id;
            }
            return val < o.val;
        }
    };
    int m, k, sumFirst, sumMiddle, sumLast, id;
    deque<Node> dq;
    set<Node, less<> > t1,t2,t3;
public:
    MKAverage(int m, int k) : m(m), k(k), sumMiddle(0), id(0) {
        
    }
    
    void addElement(int num) {
        Node newNode;
        newNode.id = id;
        ++id;
        newNode.val = num;
        dq.push_back(newNode);
        if ((int)dq.size() == m) {
            vector<Node> vec(dq.begin(),dq.end());
            sort(vec.begin(),vec.end());
            for (int i = 0; i < k; ++i) {
                t1.insert(vec[i]);
            }
            for (int i = k; i < m-k; ++i) {
                sumMiddle += vec[i].val;
                t2.insert(vec[i]);
            }
            for (int i = m-k; i < m; ++i) {
                t3.insert(vec[i]);
            }
        }
        else if ((int)dq.size() > m) {
            Node topNode = dq.front();
            dq.pop_front();
            if (t1.find(topNode) != t1.end()) {
                t1.erase(topNode);
            }
            else if (t2.find(topNode) != t2.end()) {
                t2.erase(topNode);
                sumMiddle -= topNode.val;
            }
            else {
                t3.erase(topNode);
            }
            // make sure t2 is not empty
            if (t2.empty()) {
                if (!t1.empty()) {
                    auto iter = --t1.end();
                    t2.insert(*iter);
                    sumMiddle += iter->val;
                    t1.erase(iter);
                }
                else {
                    auto iter = t3.begin();
                    t2.insert(*iter);
                    sumMiddle += iter->val;
                    t3.erase(iter);
                }
            }
            // compare and insert
            if (newNode.val < t2.begin()->val) {
                t1.insert(newNode);
            }
            else if (newNode.val > (--t2.end())->val) {
                t3.insert(newNode);
            }
            else {
                t2.insert(newNode);
                sumMiddle += newNode.val;
            }
            // re-balance
            while ((int)t1.size() > k) {
                auto iter = --t1.end();
                t2.insert(*iter);
                sumMiddle += iter->val;
                t1.erase(iter);
            }
            while ((int)t1.size() < k) {
                auto iter = t2.begin();
                t1.insert(*iter);
                sumMiddle -= iter->val;
                t2.erase(iter);
            }
            while ((int)t3.size() > k) {
                auto iter = t3.begin();
                t2.insert(*iter);
                sumMiddle += iter->val;
                t3.erase(iter);
            }
            while ((int)t3.size() < k) {
                auto iter = --t2.end();
                t3.insert(*iter);
                sumMiddle -= iter->val;
                t2.erase(iter);
            }
        }
    }
    
    int calculateMKAverage() {
        if ((int)dq.size() < m) {
            return -1;
        }
        int ans = sumMiddle / (int)t2.size();
        return ans;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */