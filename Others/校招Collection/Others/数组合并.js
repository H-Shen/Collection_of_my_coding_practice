// https://www.nowcoder.com/practice/ba9ee11affbd44539a4104d7f098f06b

function concat(arr1, arr2) {
    var arrNew = [];
    for (var i = 0; i < arr1.length; i++) {
        arrNew[i] = arr1[i];
    }
    for (var j = 0; j < arr2.length; j++) {
        arrNew[arr1.length + j] = arr2[j];
    }
    return arrNew;
}