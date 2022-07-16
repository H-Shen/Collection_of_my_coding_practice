class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> val2pos;
    vector<int> vec;
public:
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        bool answer = (val2pos.count(val) == 0);
        vec.emplace_back(val);
        val2pos[val].insert((int)vec.size()-1);
        return answer;
    }
    
    bool remove(int val) {
        if (val2pos.count(val) > 0) {
            int posToRemove = *val2pos[val].begin();
            val2pos[val].erase(posToRemove);
            if (val2pos[val].empty()) {
                val2pos.erase(val);
            }
            if (posToRemove == (int)vec.size()-1) {
                vec.pop_back();
            }
            else {
                val2pos[vec.back()].erase(vec.size()-1);
                val2pos[vec.back()].insert(posToRemove);
                vec[posToRemove] = vec.back();
                vec.pop_back();
            }
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        return vec[rand() % (int)vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */