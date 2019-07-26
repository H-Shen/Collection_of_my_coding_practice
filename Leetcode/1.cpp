class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map <int, int> A;
        vector <int> haveHalfOfTarget;

        for (size_t i = 0 ; i < nums.size(); ++i) {
            A[nums.at(i)] = static_cast<int>(i);
            if (nums.at(i) * 2 == target) {
                haveHalfOfTarget.emplace_back(i);
            }
        }

        if (haveHalfOfTarget.size() == 2) {
            return haveHalfOfTarget;
        }

        vector <int> res(2);
        for (auto it = A.begin(); it != A.end(); ++it) {
            if ( A.find(target - it->first) != A.end() &&  it->first * 2 != target ) {
                res.at(0) = it->second;
                res.at(1) = A[target - it->first];
                break;
            }
        }
        if (res.at(0) > res.at(1)) {
            swap(res.at(0), res.at(1));
        }
        return res;
    }
};