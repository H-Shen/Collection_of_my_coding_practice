// https://www.nowcoder.com/practice/5391e3118a5f419d8198264c5a8c805a

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const static size_t MAX_INPUT = 10;

class Number {
private:
    int data;
public:
    explicit Number(int data_) : data(data_) {}

    ~Number() {
        bool isNegative = false;
        if (data < 0) {
            isNegative = true;
            data = -data;
        }
        string data_str = to_string(data);
        string data_str_rev = data_str;
        reverse(data_str_rev.begin(), data_str_rev.end());
        cout << data << " ";
        if (isNegative) {
            cout << "-";
        }
        cout << stoi(data_str_rev) << endl;
    }
};

int main() {

    size_t counter = 0;
    int data;
    vector<Number *> p;
    while (true) {
        if (counter == MAX_INPUT) {
            break;
        }
        cin >> data;
        if (data == 0) {
            break;
        }
        p.emplace_back(new Number(data));
        ++counter;
    }

    for (auto &i : p) {
        delete i;
    }

    return 0;
}