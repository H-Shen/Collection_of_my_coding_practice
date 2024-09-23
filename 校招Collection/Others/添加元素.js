function prepend(arr, item) {
    var arrNew = [];
    arrNew[0] = item;
    for (var i = 0; i < arr.length; i++) {
        arrNew[i + 1] = arr[i];
    }
    return arrNew;
}