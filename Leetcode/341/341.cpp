/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> vec;
    vector<int>::iterator it;
    void dfs(NestedInteger &obj) {
        if (obj.isInteger()) {
            vec.emplace_back(obj.getInteger());
            return;
        }
        vector<NestedInteger>& vec = obj.getList();
        for (auto& i : vec) {
            dfs(i);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto& i : nestedList) {
            dfs(i);
        }
        if (vec.empty()) {
            it = vec.end();
        }
        else {
            it = vec.begin();
        }
    }
    
    int next() {
        int ans = *it;
        ++it;
        return ans;
    }
    
    bool hasNext() {
        return it != vec.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */