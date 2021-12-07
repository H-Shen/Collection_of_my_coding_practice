class BoundedBlockingQueue {
private:
    int capacity;
    deque<int> dq;
    int length;
    mutex mt{};
public:
    BoundedBlockingQueue(int capacity) : capacity(capacity), length(0) {
        
    }
    
    void enqueue(int element) {
        while (true) {
            mt.lock();
            if (length < capacity) {
                dq.push_front(element);
                ++length;
                mt.unlock();
                break;
            }
            mt.unlock();
        }
    }
    
    int dequeue() {
        int temp;
        while (true) {
            mt.lock();
            if (length > 0) {
                temp = dq.back();
                --length;
                dq.pop_back();
                mt.unlock();
                break;
            }
            mt.unlock();
        }
        return temp;
    }
    
    int size() {
        return length;
    }
};