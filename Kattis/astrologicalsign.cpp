// https://open.kattis.com/problems/astrologicalsign
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

string f(int day, int month) {
    if ( (month == 3 && day >= 21) || (month == 4 && day <= 20) ) {
        return "Aries";
    }
    if ( (month == 4 && day >= 21) || (month == 5 && day <= 20) ) {
        return "Taurus";
    }
    if ( (month == 5 && day >= 21) || (month == 6 && day <= 21) ) {
        return "Gemini";
    }
    if ( (month == 6 && day >= 22) || (month == 7 && day <= 22) ) {
        return "Cancer";
    }
    if ( (month == 7 && day >= 23) || (month == 8 && day <= 22) ) {
        return "Leo";
    }
    if ( (month == 8 && day >= 23) || (month == 9 && day <= 21) ) {
        return "Virgo";
    }
    if ( (month == 9 && day >= 22) || (month == 10 && day <= 22) ) {
        return "Libra";
    }
    if ( (month == 10 && day >= 23) || (month == 11 && day <= 22) ) {
        return "Scorpio";
    }
    if ( (month == 11 && day >= 23) || (month == 12 && day <= 21) ) {
        return "Sagittarius";
    }
    if ( (month == 12 && day >= 22) || (month == 1 && day <= 20) ) {
        return "Capricorn";
    }
    if ( (month == 1 && day >= 21) || (month == 2 && day <= 19) ) {
        return "Aquarius";
    }
    return "Pisces";
}

int convertMonth(const string& month) {
    if (month == "Jan") {
        return 1;
    }
    if (month == "Feb") {
        return 2;
    }
    if (month == "Mar") {
        return 3;
    }
    if (month == "Apr") {
        return 4;
    }
    if (month == "May") {
        return 5;
    }
    if (month == "Jun") {
        return 6;
    }
    if (month == "Jul") {
        return 7;
    }
    if (month == "Aug") {
        return 8;
    }
    if (month == "Sep") {
        return 9;
    }
    if (month == "Oct") {
        return 10;
    }
    if (month == "Nov") {
        return 11;
    }
    return 12;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int day;
    string month;
    while (n--) {
        cin >> day >> month;
        cout << f(day, convertMonth(month)) << '\n';
    }

    return 0;
}
