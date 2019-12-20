// https://www.nowcoder.com/practice/0323822699da497b8822898e90025882

function curtail(arr) {
    var arrNew = [];
    for (var i = 1; i < arr.length; i++) {
        arrNew[i - 1] = arr[i];
    }
    return arrNew;
}
