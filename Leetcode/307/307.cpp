class NumArray {
private:
    vector<int> A;
    int n, blocks;
    vector<int> block, L, R, sum;
public:
    explicit NumArray(vector<int>& nums) {
        n = static_cast<int>(nums.size());
        A.resize(n + 1);
        copy(nums.begin(), nums.end(), A.begin() + 1);
        blocks = sqrt(n);
        L.resize(blocks + 1);
        R.resize(blocks + 1);
        for (int i = 1; i <= blocks; ++i) {
            L.at(i) = (i - 1) * blocks + 1;
            R.at(i) = i * blocks;
        }
        if (R.back() < n) {
            L.emplace_back(R.back() + 1);
            R.emplace_back(n);
            ++blocks;
        }
        block.resize(n + 1);
        sum.resize(n + 1);
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                block.at(j) = i;
                sum.at(i) += A.at(j);
            }
        }
    }

    void update(int i, int val) {
        ++i;
        int block_id = block.at(i);
        sum.at(block_id) -= A.at(i);
        A.at(i) = val;
        sum.at(block_id) += A.at(i);
    }

    int sumRange(int i, int j) {
        ++i;
        ++j;
        int l_block = block.at(i);
        int r_block = block.at(j);
        int result = 0;
        if (l_block == r_block) {
            result += accumulate(A.begin() + i, A.begin() + j + 1, 0);
        } else {
            result += accumulate(sum.begin() + l_block + 1, sum.begin() + r_block, 0);
            result += accumulate(A.begin() + i, A.begin() + R.at(l_block) + 1, 0);
            result += accumulate(A.begin() + L.at(r_block), A.begin() + j + 1, 0);
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */