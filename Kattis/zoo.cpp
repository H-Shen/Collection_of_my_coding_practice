// https://open.kattis.com/problems/zoo

#include <bits/extc++.h>

using namespace std;

struct Item {
    string s;
    int freq;
};

inline
bool cmp(const Item &a, const Item &b) {
    return (a.s < b.s);
}

int main() {
    int n;
    string s;
    for (int kase = 1;; ++kase) {
        unordered_map<string, int> freq;
        cin >> n;
        if (n == 0) {
            break;
        }
        getchar();
        vector<Item> res;
        while (n--) {
            getline(cin, s);
            istringstream iss(s);
            vector<string> tmp((istream_iterator<string>(iss)), istream_iterator<string>());
            transform(tmp.back().begin(), tmp.back().end(), tmp.back().begin(),
                      [](unsigned char c) -> unsigned char { return ::tolower(c); });
            ++freq[tmp.back()];

            res.resize(freq.size());
            int pos = 0;
            for (const auto &i : freq) {
                Item tmp;
                tmp.s = i.first;
                tmp.freq = i.second;
                res[pos++] = tmp;
            }
            sort(res.begin(), res.end(), cmp);
        }

        //output
        cout << "List " << kase << ":" << endl;
        for (const auto &i : res) {
            cout << i.s << " | " << i.freq << endl;
        }
    }

    return 0;
}
