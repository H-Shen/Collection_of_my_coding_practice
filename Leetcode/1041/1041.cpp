// dir: North: 0 South: 1 West: 2 East: 3
const int LEFT[] = {2,3,1,0};
const int RIGHT[] = {3,2,0,1};

class Solution {
public:
    void go(int& r, int& c, int& dir) {
        switch (dir) {
            case 0:
                --r;
                break;
            case 1:
                ++r;
                break;
            case 2:
                --c;
                break;
            case 3:
                ++c;
                break;
        }
    }
    bool isRobotBounded(string instructions) {
        int r = 0, c = 0, dir = 0;
        for (const auto &ch : instructions) {
            switch (ch) {
                case 'G':
                    go(r, c, dir);
                    break;
                case 'L':
                    dir = LEFT[dir];
                    break;
                case 'R':
                    dir = RIGHT[dir];
                    break;
            }
        }
        return dir != 0 || (r == 0 && c == 0);
    }
};