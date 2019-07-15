// https://www.nowcoder.com/practice/edbc7496a36e433c89d298b9256af856

function remove(arr, item) {
    var newArr = [];
    var pos = 0;
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] !== item) {
            newArr[pos] = arr[i];
            pos = pos + 1;
        }
    }
    return newArr;
}