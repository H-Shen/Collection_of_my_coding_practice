constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    inline
    bool check1(int initialExperience, int extra, vector<int>& experience) const {
        int currentExperience = initialExperience + extra;
        for (auto&i : experience) {
            if (currentExperience <= i) {
                return false;
            }
            currentExperience += i;
        }
        return true;
    }
    inline 
    bool check2(int initialEnergy, int extra, vector<int>& energy) const {
        int currentEnergy = initialEnergy + extra;
        for (auto&i : energy) {
            if (currentEnergy <= i) {
                return false;
            }
            currentEnergy -= i;
        }
        return true;
    }
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = (int)energy.size();
        // obtain the extra experience
        int l = 0;
        int r = INF;
        int mid;
        int ans = INF;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check1(initialExperience, mid, experience)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        int extraExp = ans;
        // obtain the extra energy
        l = 0;
        r = INF;
        ans = INF;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check2(initialEnergy, mid, energy)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        int extraEnergy = ans;
        return extraExp + extraEnergy;
    }
};