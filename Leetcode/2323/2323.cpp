class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int n = (int)jobs.size();
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int minDays = 0;
        for (int i = 0; i < n; ++i) {
            if (jobs[i] % workers[i] == 0) {
                minDays = max(minDays, jobs[i] / workers[i]);
            }
            else {
                minDays = max(minDays, jobs[i] / workers[i] + 1);
            }
        }
        return minDays;
    }
};