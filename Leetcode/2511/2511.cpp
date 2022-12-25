class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = (int)forts.size();
        int l = -1, r = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (forts[i] == 0) {
                if (l == -1) {
                    l = i;
                    r = i;
                }
                else {
                    r = i;
                }
            }
            else {
                if (l != -1) {
                    if (l > 0 && r < n-1 && ( (forts[l-1] == 1 && forts[r+1] == -1) || (forts[l-1] == -1 && forts[r+1] == 1) ) ) {
                        ans = max(ans, r-l+1);
                    }
                    l = -1;
                }
            }
        }
        if (l != -1) {
            if (l > 0 && r < n-1 && ( (forts[l-1] == 1 && forts[r+1] == -1) || (forts[l-1] == -1 && forts[r+1] == 1) ) ) {
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};