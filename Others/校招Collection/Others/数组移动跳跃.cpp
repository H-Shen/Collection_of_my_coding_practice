// https://www.nowcoder.com/practice/3f99492e23d9403d923e44bb1061cc86

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    char ch;
    vector<int> A;
    string temp;
    while (~scanf("%c", &ch)) {
        if (ch == '[' || ch == ']') {
            continue;
        } else if (ch == ',') {
            A.emplace_back(stoi(temp));
            temp = "";
        } else {
            temp.push_back(ch);
        }
    }
    A.emplace_back(stoi(temp));

    vector<bool> vis(A.size(), false);
    int index = 0;
    try {
        while (true) {
            if (vis.at(index)) {
                printf("false\n");
                return 0;
            }
            vis.at(index) = true;
            index += A.at(index);
        }
    } catch (...) {}
    printf("true\n");
    
    return 0;
}