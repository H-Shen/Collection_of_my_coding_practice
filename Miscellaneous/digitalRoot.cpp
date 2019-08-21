#include <bits/stdc++.h>

/**
 * Calculate the digital root of random integer.
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string str;
    while (std::cin >> str) {
        if (str.front() == '-') {
            str = str.substr(1);
        }
        int num = 0;
        for (const char &ch : str) {
            num += ch - '0';
            if (num > 9)
                num = num / 10 + num % 10;
        }
        std::cout << num << std::endl;
    }
    return 0;
}
