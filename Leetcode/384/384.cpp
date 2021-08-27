class Solution {
private:
    vector<int> originalVec;
    vector<int> shuffleVec;
public:
    Solution(vector<int> nums) {
        originalVec = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuffleVec = originalVec;
        return shuffleVec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        shuffleVec = originalVec;
        random_shuffle(shuffleVec.begin(), shuffleVec.end());
        return shuffleVec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */