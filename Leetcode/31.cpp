class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        auto first = nums.begin();
        auto last = nums.end();
        auto iter = last;
        --iter;
        while (true) {
            decltype(first) iter1, iter2;
            iter1 = iter;
            if (*--iter < *iter1) {
                iter2 = last;
                while (!(*iter < *--iter2));
                iter_swap(iter, iter2);
                reverse(iter1, last);
                break;
            }
            if (iter == first) {
                reverse(first, last);
                break;
            }
        }
    }
};