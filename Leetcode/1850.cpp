vector<int> A;
vector<int> temp;
int counter = 0;

void mergeArr(int l, int r) {
    if (l >= r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    mergeArr(l, mid);
    mergeArr(mid, r);
    int p = l;
    int q = mid;
    int s = l;
    while (s < r) {
        if (p >= mid || (q < r && A[p] > A[q]) ) {
            temp[s++] = A[q++];
            counter += (mid - p);
        } else {
            temp[s++] = A[p++];
        }
    }
    for (int i = l; i < r; ++i) {
        A[i] = temp[i];
    }
}

bool cmp(const pair<char,int> &l, const pair<char,int> &r) {
    return l.first < r.first;
}

bool getNext(vector<pair<char,int> > &s) {
    int i, j;
    int n = (int)s.size();
    for (i = n - 1; i > 0; i--) {
        if (s[i].first > s[i - 1].first) {
            break;
        }
    }
    if (i == 0) {
        return false;
    }
    char x = s[i - 1].first;
    int smallest = i;
    for (j = i+1; j < n; j++) {
        if (s[j].first > x && s[j].first< s[smallest].first) {
            smallest = j;
        }
    }
    swap(s[smallest], s[i - 1]);
    sort(s.begin() + i, s.begin() + n, cmp);
    return true;
}

bool getNext(string &s) {
    int i, j;
    int n = (int)s.size();
    for (i = n - 1; i > 0; i--) {
        if (s[i] > s[i - 1]) {
            break;
        }
    }
    if (i == 0) {
        return false;
    }
    char x = s[i - 1];
    int smallest = i;
    for (j = i+1; j < n; j++) {
        if (s[j] > x && s[j] < s[smallest]) {
            smallest = j;
        }
    }
    swap(s[smallest], s[i - 1]);
    sort(s.begin() + i, s.begin() + n);
    return true;
}

class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = (int)num.size();
        vector<pair<char,int> > v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = num[i];
            v[i].second = i;
        }
        auto vCopy(v);
        while (k--) {
            getNext(v);
        }
        unordered_map<int, deque<int> > un;
        for (int i = 0; i < n; ++i) {
            un[v[i].first].emplace_back(v[i].second);
        }
        for (auto &[i, j] : un) {
            sort(j.begin(), j.end());
        }
        for (int i = 0; i < n; ++i) {
            v[i].second = un[v[i].first].front();
            un[v[i].first].pop_front();
        }
        unordered_map<int, int> unmap;
        int idx = 0;
        for (const auto &[i, j] : v) {
            unmap[j] = idx;
            ++idx;
        }
        for (int i = 0; i < n; ++i) {
            vCopy[i].second = unmap[vCopy[i].second];
        }
        vector<int>().swap(A);
        vector<int>().swap(temp);
        A.resize(n);
        temp.resize(n);
        for (int i = 0; i < n; ++i) {
            A[i] = vCopy[i].second;
        }
        counter = 0;
        mergeArr(0, n);
        return counter;
    }
};