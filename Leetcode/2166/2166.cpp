class Bitset {
private:
    vector<bool> vec;
    int size;
    int counter;
    bool allFalse;
public:
    Bitset(int size) {
        vec.resize(size, false);
        this->size = size;
        counter = 0;
        allFalse = true;
    }
    
    void fix(int idx) {
        if (!vec[idx] && allFalse) {
            vec[idx] = true;
            ++counter;
        }
        else if (vec[idx] && !allFalse) {
            vec[idx] = false;
            ++counter;
        }
    }
    
    void unfix(int idx) {
        if (vec[idx] && allFalse) {
            vec[idx] = false;
            --counter;
        }
        else if (!vec[idx] && !allFalse) {
            vec[idx] = true;
            --counter;
        }
    }
    
    void flip() {
        allFalse = !allFalse;
        counter = size - counter;
    }
    
    bool all() {
        return counter == size;
    }
    
    bool one() {
        return counter > 0;
    }
    
    int count() {
        return counter;
    }
    
    string toString() {
        string s;
        s.resize(size);
        for (int i = 0; i < size; ++i) {
            if (allFalse) {
                if (vec[i]) s[i] = '1';
                else s[i] = '0';
            }
            else {
                if (vec[i]) s[i] = '0';
                else s[i] = '1'; 
            }
        }
        return s; 
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */