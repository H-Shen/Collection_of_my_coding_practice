// https://open.kattis.com/problems/administrativeproblems
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 50;
char s[MAXN];

struct Car {
    ll catalog_price;
    ll pick_up_cost;
    ll cost_per_kilometer_driven;
};

struct Status {
    int time_tag;
    bool has_car = false;
    Car car;
    bool inconsistent = false;
    ll total_cost = 0;
};

bool cmp(const pair<string, Status> &l, const pair<string, Status> &r) {
    return l.first < r.first;
}

int main() {

    int t, n, m;
    ll catalog_price;
    ll pick_up_cost;
    ll cost_per_kilometer_driven;
    ll distance;
    ll percentage;
    string str;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        unordered_map<string, Car> carList;
        for (int i = 0; i < n; ++i) {
            scanf("%s %lld %lld %lld", s, &catalog_price, &pick_up_cost, &cost_per_kilometer_driven);
            str = s;
            carList[str].catalog_price = catalog_price;
            carList[str].pick_up_cost = pick_up_cost;
            carList[str].cost_per_kilometer_driven = cost_per_kilometer_driven;
        }
        unordered_map<string, Status> spy_status;
        int time_tag;
        string spy_name;
        for (int i = 0; i < m; ++i) {
            scanf("%d %s", &time_tag, s);
            spy_name = s;
            scanf("%s", s);
            if (strcmp(s, "p") == 0) {
                scanf("%s", s);
                // Case 1: car type is invalid
                if (carList.find(s) == carList.end()) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 2: spy has no records yet
                else if (spy_status.find(spy_name) == spy_status.end()) {
                    spy_status[spy_name].time_tag = time_tag;
                    spy_status[spy_name].has_car = true;
                    spy_status[spy_name].car = carList[s];
                    spy_status[spy_name].total_cost += spy_status[spy_name].car.pick_up_cost;
                }
                // Case 3: spy is already inconsistent
                else if (spy_status[spy_name].inconsistent) {
                    continue;
                }
                // Case 4: spy already has a car
                else if (spy_status[spy_name].has_car) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 5: the current time tag is invalid
                else if (time_tag <= spy_status[spy_name].time_tag) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 6: spy picks up a new car
                else {
                    spy_status[spy_name].time_tag = time_tag;
                    spy_status[spy_name].has_car = true;
                    spy_status[spy_name].car = carList[s];
                    spy_status[spy_name].total_cost += spy_status[spy_name].car.pick_up_cost;
                }
            }
            else if (strcmp(s, "r") == 0) {
                scanf("%lld", &distance);
                // Case 1: spy has no records yet
                if (spy_status.find(spy_name) == spy_status.end()) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 2: spy is already inconsistent
                else if (spy_status[spy_name].inconsistent) {
                    continue;
                }
                // Case 3: the current time tag is invalid
                else if (time_tag <= spy_status[spy_name].time_tag) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 4: the spy has no cars yet
                else if (!spy_status[spy_name].has_car) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 5: the spy returns the car
                else {
                    spy_status[spy_name].total_cost += spy_status[spy_name].car.cost_per_kilometer_driven * distance;
                    spy_status[spy_name].has_car = false;
                }
            }
            else {
                scanf("%lld", &percentage);
                // Case 1: spy has no records yet
                if (spy_status.find(spy_name) == spy_status.end()) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 2: spy is already inconsistent
                else if (spy_status[spy_name].inconsistent) {
                    continue;
                }
                // Case 3: the current time tag is invalid
                else if (time_tag <= spy_status[spy_name].time_tag) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 4: the spy has no cars yet
                else if (!spy_status[spy_name].has_car) {
                    spy_status[spy_name].inconsistent = true;
                }
                // Case 5: the spy pays for the accident
                else {
                    ll temp = spy_status[spy_name].car.catalog_price * percentage;
                    if (temp % 100 == 0) {
                        temp /= 100;
                    } else {
                        temp = (ll)(temp / 100.0) + 1;
                    }
                    spy_status[spy_name].total_cost += temp;
                }
            }
        }
        // All spies must return their cars
        for (auto &i : spy_status) {
            if (i.second.has_car) {
                i.second.inconsistent = true;
            }
        }

        vector<pair<string, Status> > output(spy_status.begin(), spy_status.end());
        sort(output.begin(), output.end(), cmp);
        for (const auto &[k, v] : output) {
            printf("%s ", k.c_str());
            if (v.inconsistent) {
                printf("INCONSISTENT\n");
            } else {
                printf("%lld\n", v.total_cost);
            }
        }
    }

    return 0;
}
