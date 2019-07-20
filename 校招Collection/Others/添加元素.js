// https://www.nowcoder.com/practice/3c7905cea3264ddaac4bf637ab3a19f9

function append(arr, item) {
    var arrNew = [];
    var i;
    for (i = 0; i < arr.length; i++) {
        arrNew[i] = arr[i];
    }
    arrNew[i] = item;
    return arrNew;
}