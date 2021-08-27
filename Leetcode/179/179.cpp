class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> A(nums.size());
        bool onlyZero = true;

        for (size_t i = 0; i < nums.size(); ++i) {
            A[i] = to_string(nums[i]);
            if (nums[i] != 0) {
                onlyZero = false;
            }
        }

        if (onlyZero) {
            return "0";
        }

        sort(A.begin(), A.end(), [](const string &a, const string &b) {
            string ab = a + b;
            string ba = b + a;
            return (ab > ba);
        });
        string res;
        for (const auto &i : A) {
            res += i;
        }
        return res;
    }
};