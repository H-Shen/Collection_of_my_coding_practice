class ProductOfNumbers {
private:
    vector<int> pre;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            vector<int>().swap(pre);
        } else if (pre.empty()) {
            pre.emplace_back(num);
        } else {
            pre.emplace_back(pre.back()*num);
        }
    }
    
    int getProduct(int k) {
        if (k > (int)pre.size()) {
            return 0;
        } else if (k == (int)pre.size()) {
            return pre.back();
        }
        return pre.back() / pre[(int)pre.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */