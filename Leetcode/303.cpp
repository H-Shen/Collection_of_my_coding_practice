class NumArray {
private:
    vector<int> nums_;
    vector<long long> sum;
public:
    NumArray(vector<int>& nums) : nums_ (nums) {
        sum.resize(nums.size());
        long long sumVal(0);
        for (size_t i = 0; i != nums_.size(); ++i) {
            sumVal += static_cast<long long>(nums_.at(i));
            sum.at(i) = sumVal;
        }
    }
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum.at(j);
        }
        return static_cast<int>(sum.at(j) - sum.at(i - 1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */