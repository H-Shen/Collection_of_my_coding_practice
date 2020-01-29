#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pos;
    cin >> n >> pos;
    int cnt = 1;
    string s(n, 'z');


    switch (n) {
        case 2:

            //2
            for (; s[0] >= 'a'; --s[0]) {
                for (; s[1] >= 'a'; --s[1]) {
                    if (cnt == pos) {
                        cout << s << endl;
                        return 0;
                    } else
                        ++cnt;
                }
                s[1] = 'z';
            }
            break;

        case 3:

            //3
            for (; s[0] >= 'a'; --s[0]) {
                for (; s[1] >= 'a'; --s[1]) {
                    for (; s[2] >= 'a'; --s[2]) {
                        if (cnt == pos) {
                            cout << s << endl;
                            return 0;
                        } else
                            ++cnt;
                    }
                    s[2] = 'z';
                }
                s[1] = 'z';
            }

            break;

        case 4:

            //4
            for (; s[0] >= 'a'; --s[0]) {
                for (; s[1] >= 'a'; --s[1]) {
                    for (; s[2] >= 'a'; --s[2]) {
                        for (; s[3] >= 'a'; --s[3]) {
                            if (cnt == pos) {
                                cout << s << endl;
                                return 0;
                            } else
                                ++cnt;
                        }
                        s[3] = 'z';
                    }
                    s[2] = 'z';
                }
                s[1] = 'z';
            }
            break;

        case 5:

            //5
            for (; s[0] >= 'a'; --s[0]) {
                for (; s[1] >= 'a'; --s[1]) {
                    for (; s[2] >= 'a'; --s[2]) {
                        for (; s[3] >= 'a'; --s[3]) {
                            for (; s[4] >= 'a'; --s[4]) {
                                if (cnt == pos) {
                                    cout << s << endl;
                                    return 0;
                                } else
                                    ++cnt;
                            }
                            s[4] = 'z';
                        }
                        s[3] = 'z';
                    }
                    s[2] = 'z';
                }
                s[1] = 'z';
            }
            break;

        case 6:
            //6
            for (; s[0] >= 'a'; --s[0]) {
                for (; s[1] >= 'a'; --s[1]) {
                    for (; s[2] >= 'a'; --s[2]) {
                        for (; s[3] >= 'a'; --s[3]) {
                            for (; s[4] >= 'a'; --s[4]) {
                                for (; s[5] >= 'a'; --s[5]) {
                                    if (cnt == pos) {
                                        cout << s << endl;
                                        return 0;
                                    } else
                                        ++cnt;
                                }
                                s[5] = 'z';
                            }
                            s[4] = 'z';
                        }
                        s[3] = 'z';
                    }
                    s[2] = 'z';
                }
                s[1] = 'z';
            }

    }

    return 0;
}