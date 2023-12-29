class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> vec;
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(),nums.end());
        int a, b;
        while (!pq.empty()) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            vec.emplace_back(b);
            vec.emplace_back(a);
        }
        return vec;
    }
};