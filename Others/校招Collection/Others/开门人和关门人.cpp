// https://www.nowcoder.com/practice/a4b37b53a44d454ab0834e1517983215

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct id {
    string idNum;
    int checkinHour{};
    int checkinMin{};
    int checkinSec{};
    int checkoutHour{};
    int checkoutMin{};
    int checkoutSec{};
};

inline
bool cmpLater(const id &x, const id &y) {
    if (x.checkoutHour == y.checkoutHour) {
        if (x.checkoutMin == y.checkoutMin)
            return (x.checkoutSec > y.checkoutSec);
        return (x.checkoutMin > y.checkoutMin);
    }
    return (x.checkoutHour > y.checkoutHour);
}

inline
bool cmpEarlier(const id &x, const id &y) {
    if (x.checkinHour == y.checkinHour) {
        if (x.checkinMin == y.checkinMin)
            return (x.checkinSec < y.checkinSec);
        return (x.checkinMin < y.checkinMin);
    }
    return (x.checkinHour < y.checkinHour);
}

int main() {
    int item;
    cin >> item;
    vector<id> idList(static_cast<unsigned long>(item));
    for (int i = 0; i < item; i++) {
        cin >> idList[i].idNum;
        scanf("%d:%d:%d %d:%d:%d", &idList[i].checkinHour, &idList[i].checkinMin, &idList[i].checkinSec,
              &idList[i].checkoutHour, &idList[i].checkoutMin, &idList[i].checkoutSec);
    }
    sort(idList.begin(), idList.end(), cmpEarlier);
    cout << idList[0].idNum << ' ';
    sort(idList.begin(), idList.end(), cmpLater);
    cout << idList[0].idNum << endl;
    return 0;
}
