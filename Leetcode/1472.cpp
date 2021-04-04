class BrowserHistory {
private:
    vector<string> v;
    int cur_pos;
public:
    BrowserHistory(string homepage) {
        v.emplace_back(homepage);
        cur_pos = 0;
    }
    
    void visit(string url) {
        while ((int)v.size() - 1 > cur_pos) {
            v.pop_back();
        }
        v.emplace_back(url);
        ++cur_pos;
    }
    
    string back(int steps) {
        cur_pos -= steps;
        if (cur_pos < 0) cur_pos = 0;
        return v.at(cur_pos);
    }
    
    string forward(int steps) {
        cur_pos += steps;
        if (cur_pos >= (int)v.size()) cur_pos = (int)v.size() - 1;
        return v.at(cur_pos);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */