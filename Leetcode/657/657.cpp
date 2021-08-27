class Solution {
public:
    bool judgeCircle(string moves) {
        auto pos = make_pair(0, 0);
        for (const auto &i : moves) {
            switch (i) {
                case 'U':
                    ++pos.second;
                    break;
                case 'D':
                    --pos.second;
                    break;
                case 'L':
                    --pos.first;
                    break;
                case 'R':
                    ++pos.first;
                    break;
                default:
                    break;
            }
        }
        return (!pos.first && !pos.second);
    }
};