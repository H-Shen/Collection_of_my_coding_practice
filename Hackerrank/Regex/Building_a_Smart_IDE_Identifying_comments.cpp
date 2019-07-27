#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const string commentSign0 = "//";
const string commentSign1 = "/*";
const string commentSign2 = "*/";

void sClean(string &s, int &newLen) {

    int len = static_cast<int>(s.size());
    newLen = len;
    string res;

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            newLen--;
            continue;
        } else {
            s = s.substr(static_cast<unsigned long>(i));
            break;
        }
    }

    while (!s.empty()) {
        if (s[newLen - 1] == ' ') {
            newLen--;
            s.pop_back();
        } else {
            return;
        }
    }
    newLen = 0;
}

int main() {
    vector<string> sList;

    string s;
    int newLen = 0, sListLen = 0;
    int i = 0;

    while (getline(cin, s)) {
        sClean(s, newLen);
        if (newLen != 0) {
            sList.push_back(s);
            sListLen++;
        }
    }

    size_t pos0 = 0, pos1 = 0, pos2 = 0;
    bool inComment = false;

    for (i = 0; i < sListLen; i++) {

        if (!inComment) {

            pos0 = sList[i].find(commentSign0);

            //situation0 : //
            if (pos0 != string::npos) {
                cout << sList[i].substr(pos0) << endl;
            } else {

                //situation1 : /*
                pos1 = sList[i].find(commentSign1);

                if (pos1 != string::npos) {

                    inComment = true;
                    pos2 = sList[i].find(commentSign2);

                    //situation2 : /* */
                    if (pos2 != string::npos) {
                        inComment = false;
                        cout << sList[i].substr(pos1, pos2 - pos1 + 2) << endl;
                    } else {
                        cout << sList[i].substr(pos1) << endl;
                    }
                }
            }
        } else {

            //situation3 : ...
            pos2 = sList[i].find(commentSign2);
            if (pos2 == string::npos) {
                cout << sList[i] << endl;
            }
                //situation4 : /* ... */
            else {
                inComment = false;
                cout << sList[i].substr(pos1, pos2 - pos1 + 2) << endl;
            }
        }
    }

    return 0;
}
