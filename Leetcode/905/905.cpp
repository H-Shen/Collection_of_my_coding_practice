class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        partition(A.begin(), A.end(), [](int i){
            return !(i & 1); 
        });
        return A;
    }
};