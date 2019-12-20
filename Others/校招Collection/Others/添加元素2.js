// https://www.nowcoder.com/practice/941bcfa5b87940869fda681c1597fd3a

function insert(arr, item, index) {
    return arr.slice(0, index).concat(item, arr.slice(index));
}