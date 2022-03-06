using ll = long long;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        deque<int> dq(nums.begin(),nums.end());
        sort(dq.begin(),dq.end());
        dq.erase(unique(dq.begin(),dq.end()),dq.end());
        ll sum = 0;
        int current = 1;
        while (true) {
            if (!dq.empty()) {
                if (current == dq.front()) {
                    dq.pop_front();
                    ++current;
                }
                else {
                    int diff = dq.front()-current;
                    int temp = min(k, diff);
                    sum += ((ll)current+current+temp-1)*temp/2;
                    k -= temp;
                    if (k == 0) break;
                    current += temp;
                }
            }
            else {
                if (k > 0) {
                    sum += ((ll)current+current+k-1)*k/2;
                }
                break;
            }
        }
        return sum;
    }
};