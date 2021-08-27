class FrontMiddleBackQueue {
private:
    deque<int> A, B;
    void balance() {
        int length_A = static_cast<int>(A.size());
        int length_B = static_cast<int>(B.size());
        // Case 1: make lengthA == lengthB
        if ((length_A + length_B) % 2 == 0) {
            while (length_A != length_B) {
                if (length_A > length_B) {
                    B.push_front(A.back());
                    A.pop_back();
                    ++length_B;
                    --length_A;
                }
                else {
                    A.push_back(B.front());
                    B.pop_front();
                    ++length_A;
                    --length_B;
                }
            }
        } 
        // Case 2: make lengthA + 1 == lengthB
        else {
            while (length_A + 1 != length_B) {
                if (length_A + 1 > length_B) {
                    B.push_front(A.back());
                    A.pop_back();
                    ++length_B;
                    --length_A;
                } else {
                    A.push_back(B.front());
                    B.pop_front();
                    ++length_A;
                    --length_B;
                }
            }
        }
    }
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        A.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        B.push_front(val);
        balance();
    }
    
    void pushBack(int val) {
        B.push_back(val);
        balance();
    }
    
    int popFront() {
        int result;
        if (A.empty()) {
            if (B.empty()) {
                return -1;
            } else {
                result = B.front();
                B.pop_front();
                balance();
                return result;
            }
        } else {
            result = A.front();
            A.pop_front();
            balance();
            return result;
        }
    }
    
    int popMiddle() {
        int result;
        if (A.size() == B.size()) {
            if (A.empty()) {
                return -1;
            } else {
                result = A.back();
                A.pop_back();
                balance();
                return result;
            }
        } else {
            if (B.empty()) {
                return -1;
            } else {
                result = B.front();
                B.pop_front();
                balance();
                return result;
            }
        }
    }
    
    int popBack() {
        int result;
        if (B.empty()) {
            return -1;
        } else {
            result = B.back();
            B.pop_back();
            balance();
            return result;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */