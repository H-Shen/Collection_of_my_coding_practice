class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int Gcd = numsDivide[0];
        int n = (int)numsDivide.size();
        for (int i = 1; i < n; ++i) {
            Gcd = gcd(Gcd, numsDivide[i]);
        }
        unordered_map<int,int> freq;
        for (auto&i : nums) {
            ++freq[i];
        }
        vector<pair<int,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.first < r.first;
        });
        bool haveAns = false;
        int counter = 0;
        for (auto&i : vec) {
            if (i.first <= Gcd) {
                if (Gcd % i.first == 0) {
                    haveAns = true;
                    break;
                }
                else {
                    counter += i.second;
                }
            }
            if (i.first > Gcd) {
                break;
            }
            
        }
        if (!haveAns) {
            return -1;
        }
        return counter;
    }
};