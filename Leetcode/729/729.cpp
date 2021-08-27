class MyCalendar {
private:
    vector<pair<int,int> > vec;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        --end;
        for (const auto &[i,j] : vec) {
            if ( (start >= i && start <= j) || (end >= i && end <= j) || (start <= i && end >= j) ) {
                return false;
            }
        }
        vec.emplace_back(start,end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */