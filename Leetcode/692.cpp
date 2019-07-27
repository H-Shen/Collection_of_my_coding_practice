class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map <string, int> Freq;
        for (const auto &p : words) {
            ++Freq[p];
        }

        struct A
        {
            string first;
            int second{};
            A()= default;
            A(string _first, int _second) : first(std::move(_first)), second(_second){}
            bool operator > (const A &b)
            {
                if (second == b.second) {
                    return (first < b.first);
                }
                return (second > b.second);
            }
        };

        priority_queue < A, vector <A>, greater <> > myQueue;
        for (const auto & it : Freq) {
            myQueue.push(A(it.first, it.second));
            if (static_cast<int>(myQueue.size()) > k) {
                myQueue.pop();
            }
        }

        vector <string> res(static_cast<unsigned long>(k));
        for (int i = 0; i < k; ++i) {
            res[i] = myQueue.top().first;
            myQueue.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};