import java.util.Arrays;
import java.util.Comparator;

public class KthElement {

    public static <T> void swap(T[] a, int i, int j) {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static <T> void kthElement(T[] arrayList, int k, Comparator<T> cmp) {
        int n = arrayList.length;
        assert (k >= 0 && k < n);
        int l = 0;
        int r = n - 1;
        int mid;
        while (true) {
            // the current part size is either 1 or 2
            if (r <= l + 1) {
                if (r == l + 1 && cmp.compare(arrayList[l], arrayList[r]) > 0) {
                    swap(arrayList, l, r);
                }
                return;
            }
            // order arrayList[l], arrayList[l+1], arrayList[r]
            mid = (l + r) / 2;
            swap(arrayList, mid, l + 1);
            if (cmp.compare(arrayList[l], arrayList[r]) > 0) {
                swap(arrayList, l, r);
            }
            if (cmp.compare(arrayList[l + 1], arrayList[r]) > 0) {
                swap(arrayList, l + 1, r);
            }
            if (cmp.compare(arrayList[l], arrayList[l + 1]) > 0) {
                swap(arrayList, l, l + 1);
            }
            // perform division
            // barrier is arrayList[l + 1]
            int i       = l + 1;
            int j       = r;
            T   current = arrayList[l + 1];
            while (true) {
                do {
                    ++i;
                } while (cmp.compare(arrayList[i], current) < 0);
                do {
                    --j;
                } while (cmp.compare(arrayList[j], current) > 0);
                if (i > j) {
                    break;
                }
                swap(arrayList, i, j);
            }
            // insert the barrier
            arrayList[l + 1] = arrayList[j];
            arrayList[j] = current;
            // continue to work in that part, which must contain the required element
            if (j >= k) {
                r = j - 1;
            }
            if (j <= k) {
                l = i;
            }
        }
    }

    // Leetcode 786
    public static int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n       = arr.length;
        int counter = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++counter;
            }
        }
        Pair[] a   = new Pair[counter];
        int    pos = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                a[pos] = new Pair();
                a[pos].first = arr[i];
                a[pos].second = arr[j];
                ++pos;
            }
        }
        kthElement(a, k - 1, (Pair l, Pair r) -> Integer.compare(l.first * r.second, l.second * r.first));
        return new int[]{a[k - 1].first, a[k - 1].second};
    }

    public static void main(String[] args) {
        int[] s      = {1, 7};
        int   k      = 1;
        int[] result = kthSmallestPrimeFraction(s, k);
        System.out.println(Arrays.toString(result));
    }

    static class Pair {
        Integer first, second;

        Pair(int a, int b) {
            first = a;
            second = b;
        }

        Pair() {
            this(0, 0);
        }
    }
}
