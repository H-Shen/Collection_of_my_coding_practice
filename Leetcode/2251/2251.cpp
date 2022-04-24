constexpr int MAXN = 15*1e4+5;

int A[MAXN];

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = (int)flowers.size();
        int m = (int)persons.size();
        vector<int> vec(2*n+m);
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            vec[pos++] = flowers[i][0];
            vec[pos++] = flowers[i][1];
        }
        for (int i = 0; i < m; ++i) {
            vec[pos++] = persons[i];
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()), vec.end());
        memset(A, 0, sizeof A);
        // diff array
        int l,r;
        for (int i = 0; i < n; ++i) {
            l = (int)(lower_bound(vec.begin(),vec.end(),flowers[i][0]) - vec.begin());
            r = (int)(lower_bound(vec.begin(),vec.end(),flowers[i][1]) - vec.begin());
            ++A[l];
            --A[r+1];
        }
        // restore
        int maxVal = (int)vec.size()-1;
        for (int i = 1; i <= maxVal; ++i) {
            A[i] += A[i-1];
        }
        vector<int> result(m);
        for (int i = 0; i < m; ++i) {
            result[i] = A[(int)(lower_bound(vec.begin(),vec.end(),persons[i]) - vec.begin())];
        }
        return result;
    }
};