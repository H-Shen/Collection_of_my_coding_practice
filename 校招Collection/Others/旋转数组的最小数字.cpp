// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        return (rotateArray.empty()) ? 0 : *min_element(rotateArray.begin(), rotateArray.end());
    }
};