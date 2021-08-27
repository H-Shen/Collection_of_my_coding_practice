constexpr int MAXN = 15+1;
constexpr int INF = -105;

struct myHashFunc {
    size_t operator () (const vector<int> &v) const {
        std::size_t h = 0;
        for (const auto &i : v) {
            h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bitset<MAXN> bs;
        unordered_set<vector<int>, myHashFunc > unset;
        int n = (int)nums.size();
        int total = 1 << n;
        bool haveAns;
        int counter;
        for (int i = 0; i < total; ++i) {
            haveAns = true;
            int lastOne = INF;
            counter = 0;
            for (int j = 0; j < n; ++j) {
                if (bs[j]) {
                    if (lastOne == INF) {
                        lastOne = nums[j];
                        ++counter;
                        continue;
                    }
                    if (nums[j] < lastOne) {
                        haveAns = false;
                        break;
                    }
                    else {
                        ++counter;
                        lastOne = nums[j];
                    }
                } 
            }
            if (haveAns && counter >= 2) {
                vector<int> temp;
                for (int j = 0; j < n; ++j) {
                    if (bs[j]) {
                        temp.emplace_back(nums[j]);
                    }
                }
                unset.insert(temp);
            }
            bs = bitset<MAXN>(bs.to_ulong()+1);
        }
        return vector<vector<int>>(unset.begin(),unset.end());
    }
};