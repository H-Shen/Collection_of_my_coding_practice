// https://www.nowcoder.com/practice/ec2575fb877d41c9a33d9bab2694ba47

class KthNumbers {
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        // write code here
        auto cmp = [](const pair<int, size_t> &a, const pair<int, size_t> &b) {
            return (a.first > b.first);
        };

        priority_queue < pair < int, size_t >, vector < pair < int, size_t >>, decltype(cmp) > minHeap(cmp);
        for (size_t i = 0; i != A.size(); ++i) {
            minHeap.push(make_pair(A.at(i), i));
        }

        vector <pair<int, size_t>> result(k);
        for (size_t i = 0; i != result.size(); ++i) {
            result.at(i) = minHeap.top();
            minHeap.pop();
        }

        sort(result.begin(), result.end(), [](const pair<int, size_t> &a, const pair<int, size_t> &b) {
            return a.second < b.second;
        });

        vector<int> output(k);
        for (size_t i = 0; i != result.size(); ++i) {
            output.at(i) = result.at(i).first;
        }
        return output;
    }
};