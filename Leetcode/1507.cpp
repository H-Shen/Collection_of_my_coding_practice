class Solution {
public:
    string reformatDate(string date) {
        vector<string> m = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unordered_map<string, string> months;
        int mSize = m.size();
        for (int i = 1; i <= mSize; ++i) {
            if (i < 10) {
                months[m[i-1]] = '0' + to_string(i);
            } else {
                months[m[i-1]] = to_string(i);
            }
        }
        vector<string> d = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th",
                            "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th",
                            "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th",
                            "29th", "30th", "31st"};
        int dSize = d.size();
        unordered_map<string, string> days;
        for (int i = 1; i <= dSize; ++i) {
            if (i < 10) {
                days[d[i-1]] = '0' + to_string(i);
            } else {
                days[d[i-1]] = to_string(i);
            }
        }
        istringstream iss(date);
        string stry, strm, strd;
        iss >> strd >> strm >> stry;
        return stry + '-' + months[strm] + '-' + days[strd];
    }
};