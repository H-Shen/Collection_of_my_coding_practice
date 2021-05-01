class MovingAverage {
public:
    int maxSize;
    int sum;
    deque<int> dq;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSize = size;
        sum = 0;
    }
    
    double next(int val) {
        if ((int)dq.size() < maxSize) {
            sum += val;
            dq.push_back(val);
            return sum * 1.0 / (int)dq.size();
        }
        sum -= dq.front();
        dq.pop_front();
        dq.push_back(val);
        sum += val;
        return sum * 1.0 / (int)dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */