class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {

        if (nums.empty()) {
            return vector<vector<int> >(1);
        }

        auto convert = [](const vector<int> &a) {
            string k;
            int len = static_cast<int>(a.size());
            for (int i = 0; i < len - 1; ++i) {
                k += to_string(a[i]) + ' ';
            }
            k += to_string(a[len - 1]);
            return k;
        };

        sort(nums.begin(), nums.end());
        vector<vector<int> > A;
        do {
            A.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        vector<vector<int> > A_filter;
        unordered_set<string> save;
        vector<vector<int> > res;
        string tmp;
        for (const auto &i : A) {
            tmp = convert(i);
            if (save.find(tmp) == save.end()) {
                res.push_back(i);
                save.insert(tmp);
            }
        }
        return res;
    }
};