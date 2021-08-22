constexpr int MAXN = 1e6+5;
class Solution {
public:
    vector<int> powerOfTwo;
    int getLevel(int num) {
        for (int i = 1;; ++i) {
            if (powerOfTwo[i-1] <= num && num <= powerOfTwo[i]-1) {
                return i;
            }
        }
        return -1;
    }
    int f(int level) {
        if (level == 1) {
            return 1;
        }
        return powerOfTwo[level-1]+powerOfTwo[level]-1;
    }
    vector<int> pathInZigZagTree(int label) {
        // pre
        vector<int>().swap(powerOfTwo);
        powerOfTwo.emplace_back(1);
        while (powerOfTwo.back() <= MAXN) {
            powerOfTwo.emplace_back(powerOfTwo.back()<<1);
        }
        vector<int> ans;
        int level;
        level = getLevel(label);
        while (true) {
            ans.emplace_back(label);
            if (label == 1) {
                break;
            }
            if (level & 1) {
                label = f(level-1)-(label>>1);
            }
            else {
                label = (f(level)-label)>>1;
            }
            --level;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};