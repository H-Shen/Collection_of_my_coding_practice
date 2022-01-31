constexpr int N = 9;

class Solution {
public:
    // Loop through all subsets with size r in N (Gosper's Hack)
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        int sum;
        for (int s = (1<<k)-1; s<1<<N;) {
            bitset<N> bs(s);
            // check
            sum = 0;
            for (int j = 0; j < 9; ++j) {
                if (bs[j]) {
                    sum += j+1;
                    if (sum > n) {
                        break;
                    }
                }
            }
            if (sum == n) {
                vector<int> temp;
                for (int j = 0; j < 9; ++j) {
                    if (bs[j]) {
                        temp.emplace_back(j+1);
                    }
                }
                result.emplace_back(temp);
            }
            // update
            int x = s&(-s);
            int y = s+x;
            s = ((s&(~y))/x>>1)|y;
        } 
        return result;
    }
};