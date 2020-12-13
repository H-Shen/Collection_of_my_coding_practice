class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        partition(A.begin(), A.end(), [](int i){
            return !(i & 1); 
        });
        vector<int> result(A.size());
        auto iter0 = A.crbegin();
        auto iter1 = A.cbegin();
        for (size_t i = 0; i != result.size(); ++i) {
            if (i % 2 == 0) {
                result.at(i) = *iter1;
                ++iter1;
            } else {
                result.at(i) = *iter0;
                ++iter0;
            }
        }
        return result;
    }
};