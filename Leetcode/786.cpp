bool cmp(const pair<int, int> &l, const pair<int, int> &r) {
    return l.first*r.second-l.second*r.first<0;
}

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = (int)arr.size();
        vector<pair<int, int> > A(n * n);
        int pos = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                A.at(pos++) = {arr.at(i), arr.at(j)};
            }
        }
        nth_element(A.begin(), A.begin() + k - 1, A.begin() + pos, cmp);
        return {A.at(k-1).first, A.at(k-1).second};
    }
};