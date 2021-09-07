class MyCircularDeque {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    };
    int size;
    int maxSize;
    Node* front;
    Node* last;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : size(0), maxSize(k), front(nullptr), last(nullptr) {

    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = new Node(value);
            last = front;
        } else {
            auto node = new Node(value);
            node->next = front;
            front->prev = node;
            front = node;
        }
        ++size;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = new Node(value);
            last = front;
        } else {
            auto node = new Node(value);
            node->prev = last;
            last->next = node;
            last = node;
        }
        ++size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (size == 1) {
            delete front;
            front = nullptr;
            last = nullptr;
        } else {
            auto node = front;
            front = front->next;
            front->prev = nullptr;
            delete node;
        }
        --size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (size == 1) {
            delete front;
            front = nullptr;
            last = nullptr;
        } else {
            auto node = last;
            last = last->prev;
            last->next = nullptr;
            delete node;
        }
        --size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : front->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : last->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */