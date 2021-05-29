class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        constexpr int MAXN = 26;
        vector<vector<int> > A(MAXN);
        int n = (int)releaseTimes.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                A[keysPressed[i] - 'a'].emplace_back(releaseTimes[0]);
            } else {
                A[keysPressed[i] - 'a'].emplace_back(releaseTimes[i]-releaseTimes[i-1]);
            }
        }
        vector<pair<char,int> > vec;
        for (int i = 0; i < MAXN; ++i) {
            if (!A[i].empty()) {
                vec.emplace_back(i+'a', *max_element(A[i].begin(), A[i].end()));
            }
        }
        return min_element(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first > r.first;
            }
            return l.second > r.second;
        })->first;
    }
};