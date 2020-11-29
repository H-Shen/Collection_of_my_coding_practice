class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = (int)nums.size();
        // decompose
        int blocks = sqrt(n);
        vector<int> L(blocks + 1), R(blocks + 1);
        for (int i = 1; i <= blocks; ++i) {
            L.at(i) = (i - 1) * blocks + 1;
            R.at(i) = i * blocks;
        }
        if (R.back() < n) {
            L.emplace_back(R.back() + 1);
            R.emplace_back(n);
            ++blocks;
        }
        vector<int> block(n + 1);
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                block.at(j) = i;
            }
        }
        // copy the array and sort it by blocks
        vector<int> numsAfterSort(n + 1);
        numsAfterSort.at(0) = 0;    // dummy data
        for (int i = 0; i < n; ++i) {
            numsAfterSort.at(i + 1) = nums.at(i);
        }
        for (int i = 1; i <= blocks; ++i) {
            sort(numsAfterSort.begin() + L.at(i), numsAfterSort.begin() + R.at(i) + 1);
        }
        // define a lambda that counts the number of elements in nums[l,r] (offset with 1)
        // such that element < k
        auto get_elements = [&](int l, int r, int k) -> int {
            int l_block = block.at(l);
            int r_block = block.at(r);
            int counter = 0;
            // Case 1:
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                if (numsAfterSort.at(L.at(i)) >= k) {
                    continue;
                }
                else if (numsAfterSort.at(R.at(i)) < k) {
                    counter += (R.at(i) - L.at(i) + 1);
                }
                else {
                    auto iter0 = numsAfterSort.begin() + L.at(i);
                    auto iter1 = numsAfterSort.begin() + R.at(i) + 1;
                    counter += (int)((--lower_bound(iter0, iter1, k)) - iter0 + 1);
                }
            }
            // Case 2:
            if (l_block == r_block) {
                for (int i = l; i <= r; ++i) {
                    if (nums.at(i - 1) < k) {
                        ++counter;
                    }
                }
            }
            // Case 3:
            else {
                // left block
                for (int i = l; i <= R.at(l_block); ++i) {
                    if (nums.at(i - 1) < k) {
                        ++counter;
                    }
                }
                // right block
                for (int i = L.at(r_block); i <= r; ++i) {
                    if (nums.at(i - 1) < k) {
                        ++counter;
                    }
                }
            }
            return counter;
        };
        vector<int> count(n);
        for (int i = 0; i < n; ++i) {
            count.at(i) = get_elements(i + 1, n, nums.at(i));
        }
        return count;
    }
};