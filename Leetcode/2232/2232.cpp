using ll = long long;

class Solution {
public:
    inline
    ll eval(string a, string b, string c, string d) {
        ll result = stoll(b) + stoll(c);
        if (!a.empty()) {
            result *= stoll(a);
        } 
        if (!d.empty()) {
            result *= stoll(d);
        }
        return result;
    }    
    string minimizeResult(string expression) {
        int pos = (int)expression.find('+');
        string l = expression.substr(0, pos);
        string r = expression.substr(pos+1);
        
        int n = (int)l.size();
        int m = (int)r.size();
        ll minVal = numeric_limits<ll>::max();
        string result;
        string a,b,c,d;
        for (int i = 0; i < n; ++i) {
            a = l.substr(0, i);
            b = l.substr(i);
            for (int j = 0; j < m; ++j) {
                c = r.substr(0, j+1);
                d = r.substr(j+1);
                ll temp = eval(a,b,c,d);
                if (temp < minVal) {
                    minVal = temp;
                    result = a + '(' + b + '+' + c + ')' + d;
                }
            }
        }
        return result;
    }
};