constexpr int MAXVAL = 1005;
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    bool haveAns;
    int n;
    bool vis(vector<int>&nums, int i) {
        return nums[i] < INF-MAXVAL;
    }
    void restore(vector<int>&nums, int i) {
        if (!vis(nums, i)) {
            nums[i] -= INF;
        }
    }
    int nextIndex(vector<int>&nums, int i) const {
        int index;
        if (nums[i] > 0) {
            index = (i+nums[i]) % n;
        }
        else {
            index = (i+nums[i]+MAXVAL*n) % n;
        }
        return index;
    }
    bool checkCycle(vector<int>&nums, int cycleStartIndex) const {
        int cycleLength = 1;
        int i = cycleStartIndex;
        int temp;
        while (true) {
            temp = nextIndex(nums, i);
            if (nums[i] * nums[temp] < 0) {
                return false;
            }
            i = temp;
            if (i == cycleStartIndex) {
                break;
            }
            ++cycleLength;
        }
        return cycleLength > 1;
    }
    void solve(vector<int>&nums, int startIndex) {
        if (haveAns) {
            return;
        }
        // Floyd cycle detection
        int slow = startIndex;
        int fast = startIndex;
        do {
            restore(nums, slow);
            restore(nums, fast);
            slow = nextIndex(nums, slow);
            fast = nextIndex(nums, fast);
            restore(nums, fast);
            fast = nextIndex(nums, fast);
        } while (slow != fast);
        slow = startIndex;
        while (slow != fast) {
            restore(nums, slow);
            restore(nums, fast);
            slow = nextIndex(nums, slow);
            fast = nextIndex(nums, fast);
        }
        if (checkCycle(nums, slow)) {
            haveAns = true;
        }
    }
    bool circularArrayLoop(vector<int>& nums) {
        for (auto &i : nums) {
            i += INF;   // flagged as an unvisited node
        }
        haveAns = false;
        n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (haveAns) {
                break;
            }
            if (!vis(nums, i)) {
                solve(nums, i);
            }
        }
        return haveAns;
    }
};