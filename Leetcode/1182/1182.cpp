class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> pos1, pos2, pos3;
        int n = (int)colors.size();
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 1) {
                pos1.emplace_back(i);
            }
            else if (colors[i] == 2) {
                pos2.emplace_back(i);
            }
            else {
                pos3.emplace_back(i);
            }
        }
        int m = (int)queries.size();
        vector<int> ans(m);
        int index, target;
        for (int i = 0; i < m; ++i) {
            index = queries[i][0];
            target = queries[i][1];
            if (target == 1) {
                if (pos1.empty()) {
                    ans[i] = -1;
                }
                else {
                    if (pos1.front() > index) {
                        ans[i] = pos1.front() - index;
                    }
                    else if (pos1.back() < index) {
                        ans[i] = index - pos1.back();
                    }
                    else {
                        if (binary_search(pos1.begin(),pos1.end(),index)) {
                            ans[i] = 0;
                        }
                        else {
                            auto iter = lower_bound(pos1.begin(), pos1.end(), index);
                            int diff1 = abs(*iter - index);
                            --iter;
                            int diff2 = abs(*iter - index);
                            if (diff1 <= diff2) {
                                ans[i] = diff1;
                            } else {
                                ans[i] = diff2;
                            }
                        }
                    }
                }
            }
            else if (target == 2) {
                if (pos2.empty()) {
                    ans[i] = -1;
                }
                else {
                    if (pos2.front() > index) {
                        ans[i] = pos2.front() - index;
                    }
                    else if (pos2.back() < index) {
                        ans[i] = index - pos2.back();
                    }
                    else {
                        if (binary_search(pos2.begin(),pos2.end(),index)) {
                            ans[i] = 0;
                        }
                        else {
                            auto iter = lower_bound(pos2.begin(), pos2.end(), index);
                            int diff1 = abs(*iter - index);
                            --iter;
                            int diff2 = abs(*iter - index);
                            if (diff1 <= diff2) {
                                ans[i] = diff1;
                            } else {
                                ans[i] = diff2;
                            }
                        }
                    }
                }
            }
            else {
                if (pos3.empty()) {
                    ans[i] = -1;
                }
                else {
                    if (pos3.front() > index) {
                        ans[i] = pos3.front() - index;
                    }
                    else if (pos3.back() < index) {
                        ans[i] = index - pos3.back();
                    }
                    else {
                        if (binary_search(pos3.begin(),pos3.end(),index)) {
                            ans[i] = 0;
                        }
                        else {
                            auto iter = lower_bound(pos3.begin(), pos3.end(), index);
                            int diff1 = abs(*iter - index);
                            --iter;
                            int diff2 = abs(*iter - index);
                            if (diff1 <= diff2) {
                                ans[i] = diff1;
                            } else {
                                ans[i] = diff2;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};