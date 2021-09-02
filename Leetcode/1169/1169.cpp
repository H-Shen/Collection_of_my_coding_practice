constexpr int MAXN = 1005;
constexpr int MAXAMOUNT = 1000;
constexpr int MAXTIME = 60;

class Solution {
public:
    struct Node {
        string name;
        int time;
        string city;
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        bitset<MAXN> invalid;
        int n = (int)transactions.size();
        vector<Node> v(n);
        string s;
        int amount;
        for (int i = 0; i < n; ++i) {
            istringstream iss(transactions[i]);
            getline(iss, v[i].name, ',');
            getline(iss, s, ',');
            v[i].time = stoi(s);
            getline(iss, s, ',');
            amount = stoi(s);
            getline(iss, v[i].city, ',');
            if (amount > MAXAMOUNT) {
                invalid[i] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!invalid[i]) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && v[i].name == v[j].name && abs(v[i].time-v[j].time) <= MAXTIME && v[i].city != v[j].city) {
                        invalid[i] = true;
                        invalid[j] = true;
                        break;
                    }
                }
            }
        }
        // output
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (invalid[i]) {
                ans.emplace_back(transactions[i]);
            }
        }
        return ans;
    }
};