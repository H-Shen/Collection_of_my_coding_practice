#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

class Array {
private:
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    string m_Name;
    ll m_Size;
    unordered_map<ll, ll, custom_hash> m_Array;
public:
    Array(string mName, ll mSize) : m_Name(std::move(mName)), m_Size(mSize) {}

    Array() = default;

    ll get(ll k) {
        if (m_Array.find(k) == m_Array.end()) {
            m_Array[k] = 0;
        }
        return m_Array[k];
    }

    void set(ll k, ll v) {
        m_Array[k] = v;
    }

    bool out_of_range(ll k) const {
        return k >= m_Size;
    }

    friend void print_table();
};

unordered_map<string, Array> variableTable;

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

inline static
pair<vector<string>, int> parseArray(const string &s) {
    vector<string> array_tracer;
    int last_index;
    int level = 0;
    auto iter = s.crbegin();
    while (*iter == ']') {
        ++level;
        ++iter;
    }
    int counter = 0;
    string array_name;
    auto iter_ = s.cbegin();
    while (counter < level) {
        if (*iter_ == '[') {
            array_tracer.emplace_back(array_name);
            array_name.clear();
            ++counter;
        } else {
            array_name.push_back(*iter_);
        }
        ++iter_;
    }
    string last_index_as_string;
    while (*iter_ != ']') {
        last_index_as_string.push_back(*iter_);
        ++iter_;
    }
    last_index = stoi(last_index_as_string);
    return make_pair(array_tracer, last_index);
}

inline static
bool updateAnArray(const string &s, ll new_val) {
    auto p = parseArray(s);
    // Scan from last to first
    int current_index = p.second;
    int length = static_cast<int>(p.first.size());
    for (int i = length - 1; i >= 0; --i) {
        if (variableTable[p.first[i]].out_of_range(current_index)) {
            return false;
        }
        if (i == 0) {
            variableTable[p.first[i]].set(current_index, new_val);
        } else {
            current_index = variableTable[p.first[i]].get(current_index);
        }
    }
    return true;
}

inline static
ll getFromAnArray(const string &s) {
    auto p = parseArray(s);
    // Scan from last to first
    int current_index = p.second;
    int length = static_cast<int>(p.first.size());
    ll result = -1;
    for (int i = length - 1; i >= 0; --i) {
        if (variableTable[p.first[i]].out_of_range(current_index)) {
            return -1;
        }
        if (i == 0) {
            result = variableTable[p.first[i]].get(current_index);
        } else {
            current_index = variableTable[p.first[i]].get(current_index);
        }
    }
    return result;
}

// Debugging
void print_table() {
    for (const auto &i : variableTable) {
        cout << i.second.m_Name << ' ' << i.second.m_Size << endl;
        cout << "Contents: ";
        for (const auto &[k, v] : i.second.m_Array) {
            cout << k << ":" << v << " ";
        }
        cout << endl;
    }
}

inline static bool is_integer(const std::string &str) {
    // Check if str contains any characters other than digits
    for (const char &ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

inline static
bool addAnArray(const string &s) {
    string name;
    string array_size;
    auto iter = s.cbegin();
    while (*iter != '[') {
        name.push_back(*iter);
        ++iter;
    }
    // Case 1: The stuff inside the first pair of brackets is an integer
    if (count(s.begin(), s.end(), '[') == 1) {
        ++iter;
        while (*iter != ']') {
            array_size.push_back(*iter);
            ++iter;
        }
        variableTable[name] = Array(name, stoll(array_size));
        return true;
    }
    // Case 2: The stuff inside the first pair of brackets is a number from
    // other array
    int left = s.find_first_of('[');
    int right = s.find_last_of(']');
    string inner_array = s.substr(left + 1, right - left - 1);
    ll temp_val = getFromAnArray(inner_array);
    if (temp_val == -1) {
        return false;
    }
    variableTable[name] = Array(name, temp_val);
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string command;
    vector<string> temp_vec(2);
    ll temp_val;
    while (cin >> temp_vec[0] >> temp_vec[1]) {
        if (temp_vec[0] == "int") {
            if (!addAnArray(temp_vec[1])) {
                cout << -1 << '\n';
                break;
            }
        } else if (temp_vec[0] == "cout") {
            temp_val = getFromAnArray(temp_vec[1]);
            cout << temp_val << '\n';
            if (temp_val == -1) {
                break;
            }
        } else {
            if (is_integer(temp_vec[1])) {
                if (!updateAnArray(temp_vec[0], stoi(temp_vec[1]))) {
                    cout << -1 << '\n';
                    break;
                }
            } else {
                ll new_value = getFromAnArray(temp_vec[1]);
                if (new_value == -1) {
                    cout << -1 << '\n';
                    break;
                }
                if (!updateAnArray(temp_vec[0], new_value)) {
                    cout << -1 << '\n';
                    break;
                }
            }
        }
        // print_table();
    }
    return 0;
}
