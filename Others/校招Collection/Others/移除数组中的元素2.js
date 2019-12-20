// https://www.nowcoder.com/practice/a93dd26ebb8c425d844acc17bcce9411

function removeWithoutCopy(arr, item) {
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === item) {
            arr.splice(i, 1);
            --i;
        }
    }
    return arr;
}