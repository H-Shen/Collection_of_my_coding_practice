/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static double get_distance(double lat1, double lng1,
 *                         double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
class MiniUber {
private:
    // all available drivers and their current location
    unordered_map<int, pair<double, double>> availableDrivers;
    unordered_map<int, Trip*> unavailableDrivers;
public:
    MiniUber() {
        // initialize your data structure here.
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        // Write your code here
        if (unavailableDrivers.count(driver_id) > 0) {
            return unavailableDrivers[driver_id];
        }
        availableDrivers[driver_id].first = lat;
        availableDrivers[driver_id].second = lng;
        return nullptr;
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        // Write your code here
        double minDist;
        int closestDriverId = -1;
        double temp;
        for (const auto &[k,v] : availableDrivers) {
            if (closestDriverId == -1) {
                minDist = Helper::get_distance(lat, lng, v.first, v.second);
                closestDriverId = k;
                continue;
            }
            temp = Helper::get_distance(lat, lng, v.first, v.second);
            if (temp < minDist) {
                minDist = temp;
                closestDriverId = k;
            }
        }
        if (closestDriverId == -1) {
            return nullptr;
        }
        Trip* trip = new Trip(rider_id, lat, lng);
        trip->driver_id = closestDriverId;
        availableDrivers.erase(trip->driver_id);
        unavailableDrivers[trip->driver_id] = trip;
        return trip;
    }
};