class Solution {
public:
    int convertTime(string current, string correct) {
        int a = 60*stoi(current.substr(0,2))+stoi(current.substr(3));
        int b = 60*stoi(correct.substr(0,2))+stoi(correct.substr(3));
        int counter = 0;
        while (a + 60 <= b) {
            ++counter;
            a += 60;
        }
        while (a + 15 <= b) {
            ++counter;
            a += 15;
        }
        while (a + 5 <= b) {
            ++counter;
            a += 5;
        }
        while (a + 1 <= b) {
            ++counter;
            a += 1;
        }
        return counter;
    }
};