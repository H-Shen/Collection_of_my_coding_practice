// https://www.nowcoder.com/practice/d47b482e7148497582c7a995df51f393

function callIt(fn) {
    var a = [];
    for (var i = 1 ; i < arguments.length; i++) {
        a.push(arguments[i]);
    }
    return fn.apply(null, a);
}