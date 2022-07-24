class NumberContainers {
private:
    unordered_map<int,int> index2number;
    unordered_map<int, set<int>> number2index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (index2number.count(index) > 0) {
            int oldNumber = index2number[index];
            if (oldNumber != number) {
                number2index[oldNumber].erase(index);
                if (number2index[oldNumber].empty()) {
                    number2index.erase(oldNumber);
                }
                index2number[index] = number;
                number2index[number].insert(index);
            }
        }
        else {
            index2number[index] = number;
            number2index[number].insert(index);
        }
    }
    
    int find(int number) {
        if (number2index.count(number) > 0) {
            return *number2index[number].begin();
        }
        else {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */