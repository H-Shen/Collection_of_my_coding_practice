class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return (int)count_if(hours.begin(),hours.end(),[&](const int &val){return val >= target;});
    }
};