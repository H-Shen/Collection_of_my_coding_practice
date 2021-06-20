class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        constexpr int MAXN = 50*60;
        bitset<MAXN> vis;
        int st = stoi(startTime.substr(0,2))*60+stoi(startTime.substr(3,2));
        int et = stoi(finishTime.substr(0,2))*60+stoi(finishTime.substr(3,2));
        if (et < st) {
            et += 24*60;
        }
        for (int i = 0; i <= 48; ++i) {
            for (int j = 0; j <= 59; j += 15) {
                vis[i*60+j] = true;
            }
        }
        int ans = 0;
        for (int i = st; i <= et; ++i) {
            if (vis[i]) {
                ++ans;
            }
        }
        return ans-1;
    }
};