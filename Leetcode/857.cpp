int sgn(const double &x) {
    static const double EPS = 1e-7;
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = (int)quality.size();
        vector<pair<int,int> > vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = quality[i];
            vec[i].second = wage[i];
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int> &l, const pair<int,int> &r) {
            double unitWageL = l.second * 1.0 / l.first;
            double unitWageR = r.second * 1.0 / r.first;
            return sgn(unitWageL - unitWageR) < 0;
        });
        priority_queue<int> pq;     // store quality
        int quality_sum = 0;
        double ans = -1;
        bool ansInit = false;
        double currentUnitWage;
        for (int i = 0; i < n; ++i) {
            currentUnitWage = vec[i].second * 1.0 / vec[i].first;
            quality_sum += vec[i].first;
            while ((int)pq.size() > k - 1) {
                quality_sum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k - 1) {
                if (!ansInit) {
                    ansInit = true;
                    ans = quality_sum * currentUnitWage;
                } else {
                    ans = min(ans, quality_sum * currentUnitWage);
                }
            }
            pq.push(vec[i].first);
        }
        return ans;
    }
};