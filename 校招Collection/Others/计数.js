// https://www.nowcoder.com/practice/628339bd8e6e440590ad86caa7ac6849

function count(arr, item) {
    return arr.filter(function(a){
        return (a==item);
    }).length
}