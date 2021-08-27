class MaxStack {
public:
    list<int> s;
    map<int, vector<list<int>::iterator>, greater<> > m;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s.emplace_back(x);
        m[x].emplace_back(--s.end());
    }
    
    int pop() {
        auto it = s.end();
        --it;
        int temp = *it;
        m[temp].pop_back();
        s.pop_back();
        if (m[temp].empty()) {
            m.erase(temp);
        }
        return temp;
    }
    
    int top() {
        return s.back();
    }
    
    int peekMax() {
        return m.begin()->first;
    }
    
    int popMax() {
        auto iter = m.begin();
        int maxValue = iter->first;
        auto iter2 = iter->second.back();
        s.erase(iter2);
        iter->second.pop_back();
        if (iter->second.empty()) {
            m.erase(iter);   
        }
        return maxValue; 
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */