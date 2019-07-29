class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0;
        int tail = static_cast<int>(numbers.size()) - 1;
        int temp = numbers.at(head) + numbers.at(tail);
        while (temp != target) {
            if (temp < target) {
                ++head;
            } else {
                --tail;
            }
            temp = numbers.at(head) + numbers.at(tail);
        }
        return vector<int>{head + 1, tail + 1};
    }
};