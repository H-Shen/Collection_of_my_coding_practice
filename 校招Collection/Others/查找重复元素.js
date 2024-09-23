// https://www.nowcoder.com/practice/871a468deecf453589ea261835d6b78b

function duplicates(arr) {
    var arrNew = [];

    if (arr.length === 1) {
        return arrNew;
    }

    var arrHash = [];
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] in arrHash) {
            arrHash[arr[i]] = arrHash[arr[i]] + 1;
        }
        else {
            arrHash[arr[i]] = 1;
        }
    }

    var pos = 0;
    for (key in arrHash) {
        if (arrHash[key] > 1) {
            arrNew[pos] = key;
            pos++;
        }
    }
    return arrNew;
}