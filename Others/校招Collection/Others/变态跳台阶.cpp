// https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387

class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << (number - 1);
    }
};