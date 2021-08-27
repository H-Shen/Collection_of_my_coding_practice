class MyCircularQueue {
private:
    vector<int> mQueue;
    int mSize;
    int head;
    int tail;
public:
    // the circular queue can store k elements
    // we use k+1 because we need an additional empty slot
    MyCircularQueue(int k) : mSize(k+1), head(0), tail(0) {
        mQueue.resize(mSize);
    }
    
    bool enQueue(int value) {
        if (this->isFull()) {
            return false;
        }
        mQueue[tail] = value;
        tail = (tail+1) % mSize;
        return true;
    }
    
    bool deQueue() {
        if (this->isEmpty()) {
            return false;
        }
        head = (head+1) % mSize;
        return true;
    }
    
    int Front() {
        return (this->isEmpty()) ? -1 : mQueue[head];
    }
    
    int Rear() {
        if (this->isEmpty()) {
            return -1;
        }
        int new_pos = tail-1;
        if (new_pos < 0) {
            new_pos += mSize;
        }
        return mQueue[new_pos];
    }
    
    bool isEmpty() {
        return tail == head;
    }
    
    bool isFull() {
        return (tail+1) % mSize == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */