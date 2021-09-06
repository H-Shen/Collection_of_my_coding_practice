bool cmp(const pair<int,int>& l, const pair<int,int>&r) {
    return l.first < r.first;
}

class Solution {
public:
    // O(nlogn)
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        int n = (int)properties.size();
        vector<pair<int,int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i].first = properties[i][0];
            A[i].second = properties[i][1];
        }
        sort(A.begin(),A.end(),cmp);
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = A[n-1].second;
        for (int i = n-2; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i+1], A[i].second);
        }
        int counter = 0;
        pair<int,int> temp;
        temp.second = -1;
        for (int i = 0; i < n; ++i) {
            temp.first = A[i].first;
            auto iter = upper_bound(A.begin(),A.end(),temp,cmp);
            if (iter != A.end() && A[i].second < maxFromRight[(int)(iter-A.begin())]) {
                ++counter;
            }
        }
        return counter;
    }
};