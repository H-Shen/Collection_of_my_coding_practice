#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    unordered_set<char> result(arr.front().begin(), arr.front().end());
    if (arr.size() == 1) {
        return result.size();
    }

    auto getIntersection = [](const unordered_set<char> &A, const unordered_set<char> &B) -> unordered_set<char> {
        vector<char> vec_A(A.begin(), A.end());
        vector<char> vec_B(B.begin(), B.end());
        sort(vec_A.begin(), vec_A.end());
        sort(vec_B.begin(), vec_B.end());
        vector<char> vec_result;
        set_intersection(vec_A.begin(), vec_A.end(), vec_B.begin(), vec_B.end(), back_inserter(vec_result));
        return unordered_set<char>(vec_result.begin(), vec_result.end());
    };

    for (size_t i = 1; i != arr.size(); ++i) {
        unordered_set<char> temp(arr.at(i).begin(), arr.at(i).end());
        result = getIntersection(result, temp);
    }
    return result.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
