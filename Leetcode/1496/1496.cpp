class Solution {
public:
    bool isPathCrossing(string path) {
        struct myHash {
            size_t operator ()(const pair<int,int> &pos) const {
                return hash<int>()(pos.first) ^ hash<int>()(pos.second);
            }
        };
        unordered_set<pair<int,int>, myHash> unset;
        int x = 0, y = 0;
        unset.insert({x, y});
        for (const char &ch : path) {
            switch (ch) {
                case 'N':
                    ++y;
                    break;
                case 'S':
                    --y;
                    break;
                case 'E':
                    --x;
                    break;
                case 'W':
                    ++x;
                    break;
            }
            if (unset.find({x,y}) != unset.end()) return true;
            unset.insert({x, y});
        }
        return false;
    }
};