class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> A(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                A[i-1] = "FizzBuzz"; 
            } else if (i % 3 != 0 && i % 5 != 0) {
                A[i-1] = to_string(i);
            } else if (i % 3 == 0) {
                A[i-1] = "Fizz";
            } else {
                A[i-1] = "Buzz";
            }
        }
        return A;
    }
};