// https://www.nowcoder.com/practice/6fadc1dac83a443c9434f350a5803b51

class Printer {
public:
    vector<int> arrayPrint(vector <vector<int>> arr, int n) {
        const int initial = -123456;
        for (int i = 0; i < n; i++) {
            reverse(arr[i].begin(), arr[i].end());
        }

        vector<int> item(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            item[i] = initial;
        }

        vector <vector<int>> a(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            a[i] = item;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][i + j] = arr[i][j];
            }
        }

        vector<int> result(n * n);
        int pos = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                int current = a[j][i];
                if (current != initial) {
                    result[pos] = current;
                    pos++;
                }
            }
        }
        return result;
    }
};