class Solution {
public:
    int ans, n;
    void setBit(int &s, int j) {
        s |= (1 << j);
    }
    bool isOn(int s, int j) {
        return (s & (1 << j));
    }
    void dfs(const vector<string> &arr, int i, int length, int status) {
        ans = max(ans,length);
        bool noDup;
        int statusInCurrStr;
        for (int j = i+1; j < n; ++j) {
            noDup = true;
            for (const char &ch : arr[j]) {
                if (isOn(status, ch - 'a')) {
                    noDup = false;
                    break;
                }
            }
            if (noDup) {
                statusInCurrStr = 0;
                for (const char &ch : arr[j]) {
                    if (isOn(statusInCurrStr, ch - 'a')) {
                        noDup = false;
                        break;
                    }
                    setBit(statusInCurrStr, ch - 'a');
                }
            }
            if (noDup) {
                int newStatus = status;
                for (const char &ch : arr[j]) {
                    setBit(newStatus, ch - 'a');
                }
                dfs(arr,j,length+(int)arr[j].size(),newStatus);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        ans = 0;
        n = (int)arr.size();
        bool noDup;
        int status;
        for (int i = 0; i < n; ++i) {
            status = 0;
            noDup = true;
            for (const char &ch : arr[i]) {
                if (isOn(status, ch - 'a')) {
                    noDup = false;
                    break;
                }
                setBit(status, ch - 'a');
            }
            if (noDup) {
                dfs(arr,i,(int)arr[i].size(),status);
            }
        }
        return ans;
    }
};