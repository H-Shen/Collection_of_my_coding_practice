class KthLargest {
private:
    priority_queue<int, vector<int>, greater<>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const auto &i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if ((int)minHeap.size() < k) {
            minHeap.push(val);
        }
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */