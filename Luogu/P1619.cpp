#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using int128 = __int128;

constexpr ll MAX_NUMBER = 40000000;
constexpr int MAX_STR_LEN = 200;

// 0: successfully obtain the int64 number
// 1: no digits found
// 2: the number is larger than any int64
int check(const string &s, ll &a) {
    string number;
    for (const char &ch : s) {
        if (isdigit(ch)) {
            number.push_back(ch);
        }
    }
    if (number.empty()) {
        return 1;
    }
    try {
        a = stoll(number);
        if (a > MAX_NUMBER) {
            return 2;
        }
    } catch (...) {
        return 2;
    }
    return 0;
}

vector<pair<ll, int> > get_primes(const string &a) {

    static FILE *fp;
    static string command, output;
    static char output_buffer[MAX_STR_LEN];
#ifdef __APPLE__
    command = "gfactor " + a;
#else
    command = "factor " + a;
#endif
    fp = popen(command.c_str(), "r");
    if (!fp) {
        exit(-1);
    }
    fgets(output_buffer, sizeof(output_buffer), fp);
    output = output_buffer;
    output.pop_back();
    vector<pair<ll, int> > result;
    istringstream f(output);
    unordered_map<ll, int> result_of_parse;
    bool first_item = true;
    while (getline(f, output, ' ')) {
        if (first_item) {
            first_item = false;
        } else {
            ++result_of_parse[stoll(output)];
        }
    }
    for (const auto &[k, v] : result_of_parse) {
        result.emplace_back(make_pair(k, v));
    }
    sort(result.begin(), result.end(),
         [](const pair<ll, int> &l, const pair<ll, int> &r) {
             return l.first < r.first;
         });
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    vector<pair<ll, int> > temp_vec;
    ll a;
    int temp;
    bool first_item;
    bool first_case = true;
    while (getline(cin, input)) {
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        cout << "Enter the number=" << '\n';
        temp = check(input, a);
        if (temp == 1) {
            break;
        }
        if (a < 2) {
            cout << "Prime? No!" << '\n';
        } else {
            temp_vec = get_primes(to_string(a));
            if (temp_vec.size() == 1 && temp_vec.begin()->second == 1) {
                cout << "Prime? Yes!" << '\n';
            } else {
                cout << "Prime? No!" << '\n';
                // output the factorization if it is a small number
                if (temp == 0) {
                    cout << a << '=';
                    first_item = true;
                    for (const auto &[k, v] : temp_vec) {
                        if (first_item) {
                            first_item = false;
                        } else {
                            cout << '*';
                        }
                        cout << k << '^' << v;
                    }
                    cout << '\n';
                }
            }
        }
        if (temp == 2) {
            cout << "The number is too large!" << '\n';
        }
    }

    return 0;
}