class Solution {
private:
    static const int LOCAL_NUMBER_LENGTH = 10;
public:
    string maskPII(string s) {
        // Case 1: email address
        string result;
        if (s.find('@') != string::npos) {
            string name, domain;
            int i = 0;
            for (; i < (int)s.size(); ++i) {
                if (s[i] == '@') {
                    break;
                }
                name.push_back(s[i]);
            }
            ++i;
            for (; i < (int)s.size(); ++i) {
                domain.push_back(s[i]); 
            }
            name = (char)tolower(name.front()) + string("*****") + (char)tolower(name.back());
            for (auto& ch : domain) {
                ch = tolower(ch);
            }
            result = name + '@' + domain;
        }
        // Case 2: phone number
        else {
            string digits;
            for (auto&ch : s) {
                if (isdigit(ch)) {
                    digits.push_back(ch);
                }
            }
            int remain = (int)digits.size() - LOCAL_NUMBER_LENGTH;
            if (remain == 0) {
                result = string("***-***-") + digits.substr((int)digits.size()-4);
            }
            else if (remain == 1) {
                result = string("+*-***-***-") + digits.substr((int)digits.size()-4);
            }
            else if (remain == 2) {
                result = string("+**-***-***-") + digits.substr((int)digits.size()-4);
            }
            else {
                result = string("+***-***-***-") + digits.substr((int)digits.size()-4);
            }
        }
        return result;
    }
};