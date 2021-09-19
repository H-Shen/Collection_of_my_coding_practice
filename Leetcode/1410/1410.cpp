class Solution {
public:
    string entityParser(string text) {
        string res;
        int n = (int)text.size();
        for (int i = 0; i < n; ) {
            if (text[i] == '&') {
                if (i+6<n && text[i+1]=='f' && text[i+2]=='r' && text[i+3]=='a' && text[i+4]=='s' && text[i+5]=='l' && text[i+6]==';') {
                    res.push_back('/');
                    i += 7;
                }
                else if (i+5<n && text[i+1]=='q' && text[i+2]=='u' && text[i+3]=='o' && text[i+4]=='t' && text[i+5]==';') {
                    res.push_back('"');
                    i += 6;
                }
                else if (i+5<n && text[i+1]=='a' && text[i+2]=='p' && text[i+3]=='o' && text[i+4]=='s' && text[i+5]==';') {
                    res.push_back('\'');
                    i += 6;
                }
                else if (i+4<n && text[i+1]=='a' && text[i+2]=='m' && text[i+3]=='p' && text[i+4]==';') {
                    res.push_back('&');
                    i += 5;
                }
                else if (i+3<n && text[i+1]=='g' && text[i+2]=='t' && text[i+3]==';') {
                    res.push_back('>');
                    i += 4;
                }
                else if (i+3<n && text[i+1]=='l' && text[i+2]=='t' && text[i+3]==';') {
                    res.push_back('<');
                    i += 4;
                }
                else {
                    res.push_back('&');
                    ++i;
                }
            }
            else {
                res.push_back(text[i]);
                ++i;
            }
        }
        return res;
    }
};