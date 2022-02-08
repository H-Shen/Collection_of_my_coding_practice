class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = (int)intervals.size();
        // 2d compression
        vector<int> vec(n<<1);
        for (int i = 0, j = 0; i < n; ++i) {
            vec[j++] = intervals[i][0];
            vec[j++] = intervals[i][1];
        }
        vec.insert(upper_bound(vec.begin(),vec.end(),toBeRemoved[0]),toBeRemoved[0]);
        vec.insert(upper_bound(vec.begin(),vec.end(),toBeRemoved[1]),toBeRemoved[1]);
        vec.erase(unique(vec.begin(),vec.end()), vec.end());
        vector<int> A((int)vec.size()+5, 0);
        for (auto&i : intervals) {
            int l = (int)(lower_bound(vec.begin(),vec.end(),i[0]) - vec.begin());
            int r = (int)(lower_bound(vec.begin(),vec.end(),i[1]) - vec.begin());
            for (int j = l+1; j <= r; ++j) {
                A[j] = 1;
            }
        }
        int l = (int)(lower_bound(vec.begin(),vec.end(),toBeRemoved[0]) - vec.begin());
        int r = (int)(lower_bound(vec.begin(),vec.end(),toBeRemoved[1]) - vec.begin());
        for (int j = l+1; j <= r; ++j) {
            if (A[j] == 1) A[j] = 0;
        }
        int length = (int)A.size();
        int startIndex = -1;
        int endIndex = -1;
        // calculate and restore
        vector<vector<int>> ans;
        for (int i = 1; i < length; ++i) {
            if (A[i] == 1) {
                if (startIndex == -1) {
                    startIndex = i;
                }
                endIndex = i;
            }
            else {
                if (startIndex != -1) {
                    ans.emplace_back(vector<int>{vec[startIndex-1],vec[endIndex]});
                    startIndex = -1;
                }
            }
        }
        if (startIndex != -1) {
            ans.emplace_back(vector<int>{vec[startIndex-1],vec[endIndex]});
        }
        return ans;
    }
};