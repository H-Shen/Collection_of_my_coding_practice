class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        deque<int> d(bits.begin(), bits.end());
        while (true) {
            if (d.size() == 1) {
                return true;
            }
            else if (d.size() == 2) {
                return d.at(0) != 1;
            }
            else if (d.front() == 0) {
                d.pop_front();
            }
            else {
                d.pop_front();
                d.pop_front();
            }
        }
        return false;
    }
};