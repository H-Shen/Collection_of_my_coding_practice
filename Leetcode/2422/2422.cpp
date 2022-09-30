using ll = long long;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        deque<ll> dq(nums.begin(),nums.end());
        int counter = 0;
        ll temp;
        while (true) {
            if (dq.size() <= 1) {
                break;
            }
            if (dq.front() == dq.back()) {
                dq.pop_front();
                dq.pop_back();
            }
            else if (dq.front() > dq.back()) {
                temp = dq.back();
                dq.pop_back();
                temp += dq.back();
                dq.pop_back();
                dq.push_back(temp);
                ++counter;
            }
            else {
                temp = dq.front();
                dq.pop_front();
                temp += dq.front();
                dq.pop_front();
                dq.push_front(temp);
                ++counter;
            }
        }
        return counter;
    }
};