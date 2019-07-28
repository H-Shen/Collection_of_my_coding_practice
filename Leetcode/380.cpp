class RandomizedSet {
private:
    unordered_map <int, int> val2idx;
    vector <int> valList;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        val2idx.clear();
        vector <int>().swap(valList);
        srand(static_cast<unsigned>(time(nullptr)));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val2idx.find(val) != val2idx.end()) {
            return false;
        }
        val2idx[val] = static_cast<int>(valList.size());
        valList.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val2idx.find(val) == val2idx.end()) {
            return false;
        }
        int tmpPos = val2idx[val];
        valList[tmpPos] = valList.back();
        valList.pop_back();
        val2idx[valList[tmpPos]] = tmpPos;
        val2idx.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return valList[rand() % (valList.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */