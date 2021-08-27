class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> A, temp;
    int counter;
    void mergeArr(int l, int r) {
        if (l >= r - 1) {
            return;
        }
        int mid = l + ((r - l) >> 1);
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
    int getMinSwaps(string num, int k) {
        int n = (int)num.size();
        vector<pair<char,int> > v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = num[i];
            v[i].second = i;
        }
        auto vCopy(v);
        while (k--) {
            next_permutation(v.begin(), v.end(), [](const auto &l, const auto &r){
                return l.first < r.first;
            });
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