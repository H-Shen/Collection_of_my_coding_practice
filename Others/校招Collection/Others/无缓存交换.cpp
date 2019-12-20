// https://www.nowcoder.com/practice/845ec89145b04b2b855d020d9c3ea2ef

class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        // write code here
        AB[0] = AB[0] + AB[1];
        AB[1] = AB[0] - AB[1];
        AB[0] = AB[0] - AB[1];
        return AB;
    }
};