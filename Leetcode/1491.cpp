class Solution {
public:
    double average(vector<int>& salary) {
        auto p = minmax_element(salary.begin(), salary.end());
        return (accumulate(salary.begin(), salary.end(), 0) - (*(p.first)) - (*(p.second))) * 1.0 / ((int)salary.size() - 2);
    }
};