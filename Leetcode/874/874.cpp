struct myHashFunc {
    size_t operator()(const pair<int,int> &o) const {
        size_t h = 0;
        h ^= hash<int>{}(o.first) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<int>{}(o.second) + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

constexpr int STEPS = 4;
// 0: N 1: E 2: S 3: W
int turnRight[] = {1,2,3,0};
int turnLeft[] = {3,0,1,2};

pair<int,int> nextStep(const pair<int,int> &p, int dir) {
    pair<int,int> ans = p;
    switch (dir) {
        case 0:
            ++ans.second;
            break;
        case 1:
            ++ans.first;
            break;
        case 2:
            --ans.second;
            break;
        case 3:
            --ans.first;
            break;
    }
    return ans;
}



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int,int>, myHashFunc> unset;
        for (const auto &i : obstacles) {
            unset.insert({i[0],i[1]});
        }
        int ans = 0;
        pair<int,int> pos;
        int dir = 0;
        pair<int,int> nextPos;
        for (const auto &i : commands) {
            if (i == -2) {
                dir = turnLeft[dir];
            }
            else if (i == -1) {
                dir = turnRight[dir];
            }
            else {
                for (int step = 1; step <= i; ++step) {
                    nextPos = nextStep(pos, dir);
                    if (unset.find(nextPos) == unset.end()) {
                        pos = nextPos;
                        ans = max(ans, pos.first*pos.first+pos.second*pos.second);
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};