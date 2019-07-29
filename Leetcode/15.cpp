class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        unordered_map<int, int> num_log;
        int len = static_cast<int>(num.size()), pos = 0;
        int i;
        for (i = 0; i < len; i++) {
            if (num_log.find(num[i]) == num_log.end()) {
                num_log[num[i]]++;
                pos++;
            } else if (num_log[num[i]] < 3) {
                num_log[num[i]]++;
                pos++;
            }
        }
        vector<int> num_sieve(static_cast<unsigned long>(pos));
        int posLog = 0;
        for (auto &it : num_log) {
            for (i = 0; i < it.second; i++) {
                num_sieve[posLog] = it.first;
                posLog++;
            }
        }
        vector<vector<int> > result_vec;
        set<vector<int> > result_set;
        sort(num_sieve.begin(), num_sieve.end());

        int firstPtr, secondPtr, thirdPtr, crnVal;

        for (firstPtr = 0; firstPtr < pos - 2; firstPtr++) {
            secondPtr = firstPtr + 1;
            thirdPtr = pos - 1;
            while (secondPtr < thirdPtr) {
                crnVal = num_sieve[firstPtr] + num_sieve[secondPtr] + num_sieve[thirdPtr];
                if (crnVal < 0)
                    secondPtr++;
                else if (crnVal > 0)
                    thirdPtr--;
                else {
                    vector<int> temp = {num_sieve[firstPtr], num_sieve[secondPtr], num_sieve[thirdPtr]};
                    result_set.insert(temp);
                    secondPtr++;
                }
            }
        }
        copy(result_set.begin(), result_set.end(), back_inserter(result_vec));
        return result_vec;
    }
};