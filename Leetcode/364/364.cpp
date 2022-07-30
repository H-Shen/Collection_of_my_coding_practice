/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int sum;
    int maxDepth;
    void dfs1(NestedInteger& i, int depth) {
        maxDepth = max(maxDepth, depth);
        if (!i.isInteger()) {
            vector<NestedInteger>& vec = i.getList();
            for (auto& j : vec) {
                dfs1(j, depth+1);
            }
        }
    }
    void dfs2(NestedInteger& i, int depth) {
        if (i.isInteger()) {
            sum += i.getInteger() * (maxDepth - depth + 1);
        }
        else {
            vector<NestedInteger>& vec = i.getList();
            for (auto& j : vec) {
                dfs2(j, depth+1);
            }
        }
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        sum = 0;
        maxDepth = 0;
        for (auto&i : nestedList) {
            dfs1(i, 1);
        }
        for (auto&i : nestedList) {
            dfs2(i, 1);
        }
        return sum;
    }
};