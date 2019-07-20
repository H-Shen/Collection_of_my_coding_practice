// https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1

class Solution {
public:
    vector<int> arr;
    priority_queue<int> smallerHeap;
    priority_queue<int, vector<int>, greater<> > greaterHeap;
    int midVal = 0;
    double midValDouble = 0.0;
    int arrLen = 0;

    void Insert(int num) {
        arr.push_back(num);
        if (arrLen == 0) {
            midVal = arr[0];
            midValDouble = arr[0];
            ++arrLen;
            return;
        }
        if (num > midVal) {
            greaterHeap.push(num);
        } else {
            smallerHeap.push(num);
        }

        if (greaterHeap.size() == smallerHeap.size() + 2) {
            smallerHeap.push(midVal);
            midVal = greaterHeap.top();
            greaterHeap.pop();
        } else if (smallerHeap.size() > greaterHeap.size()) {
            greaterHeap.push(midVal);
            midVal = smallerHeap.top();
            smallerHeap.pop();
        }

        ++arrLen;
        if (arrLen % 2 != 0) {
            midValDouble = midVal;
        } else {
            midValDouble = (midVal + greaterHeap.top()) / 2.0;
        }
    }

    double GetMedian() {
        return midValDouble;
    }
};