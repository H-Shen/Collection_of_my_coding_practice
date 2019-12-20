// https://www.nowcoder.com/practice/0a9af9cb20c34babb6232126e019c74d

function findAllOccurrences(arr, target) {
    var newArr = [];
    var pos = 0;
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            newArr[pos] = i;
            ++pos;
        }
    }
    return newArr;
}