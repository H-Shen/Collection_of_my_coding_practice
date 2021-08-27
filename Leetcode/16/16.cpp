class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

        int MAX = 0x3f3f3f3f;
        sort(num.begin(), num.end());
        int firstPtr, secondPtr, thirdPtr;
        int diff = MAX, diffSum = 0;
        int tempDiff, tempSum;
        int len = num.size();

        for (firstPtr = 0; firstPtr < len - 2; firstPtr++) {

            secondPtr = firstPtr + 1;
            thirdPtr = len - 1;

            while (secondPtr != thirdPtr) {
                tempSum = num[firstPtr] + num[secondPtr] + num[thirdPtr];
                tempDiff = abs(tempSum - target);
                if (tempDiff < diff) {
                    diffSum = tempSum;
                    diff = tempDiff;
                }
                if (tempSum < target)
                    secondPtr++;
                else if (tempSum > target)
                    thirdPtr--;
                else
                    return tempSum;
            }
        }
        return diffSum;
    }
};