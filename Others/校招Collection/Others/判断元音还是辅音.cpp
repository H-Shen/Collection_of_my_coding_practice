// https://www.nowcoder.com/practice/7eb4df4d52c44d309081509cf52ecbc4
// Compiled in C++14(g++5.4)
 
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    
    string vowels = "aeiouAEIOU";
    unordered_set<char> unset(vowels.begin(), vowels.end());
    char ch;
    while (cin >> ch) {
        cin.get();
        if (unset.find(ch) != unset.end()) {
            cout << "Vowel";
        } else {
            cout << "Consonant";
        }
        cout << endl;
    }
     
    return 0;
}