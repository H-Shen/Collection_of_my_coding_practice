// https://www.nowcoder.com/practice/e7835a8113dd48afb15f77ef8d1dcb1d

function indexOf(arr, item) {
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === item) {
            return i;
        }
    }
    return -1;
}
