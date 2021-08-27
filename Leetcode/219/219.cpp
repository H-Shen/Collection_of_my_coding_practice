class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {

        auto differJudge = [](const vector<int> &A, const int &k) {
            for (size_t i = 0; i < A.size() - 1; ++i) {
                if (abs(A[i] - A[i + 1]) <= k) {
                    return true;
                }
            }
            return false;
        };

        bool res = false;
        //iteration
        unordered_map<int, vector<int> > A;
        for (size_t i = 0; i < nums.size(); ++i) {
            A[nums[i]].push_back(i);
        }

        //filter i and j
        for (const auto &it : A) {
            if (it.second.size() > 1 && differJudge(it.second, k)) {
                res = true;
                break;
            }
        }
        return res;
    }
};