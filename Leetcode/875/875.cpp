class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        int counter = 0;
        for (auto&i : piles) {
            counter += i / k;
            if (i % k > 0) ++counter;
            if (counter > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = (int)piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int mid;
        int ans = numeric_limits<int>::max();
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (check(piles, h, mid)) {
                ans = min(ans, mid);
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};