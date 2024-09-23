#include <iostream>

using namespace std;
const int MAX = 60;

int main() {

    ios_base::sync_with_stdio(false);
    int time, pass;
    cin >> time >> pass;
    string timeStr = to_string(time);

    if (timeStr.size() == 3) {
        timeStr = '0' + timeStr;
    }

    int hour = stoi(string(timeStr.begin(), timeStr.begin() + 2));
    int minute = stoi(string(timeStr.begin() + 2, timeStr.end()));
    int currentTime = hour * MAX + minute + pass;

    int currentHour = currentTime / MAX;
    int currentMinute = currentTime % MAX;

    cout << currentHour << ((currentMinute < 10) ? "0" : "")
         << currentMinute << endl;
}