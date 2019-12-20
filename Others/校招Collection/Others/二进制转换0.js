// https://www.nowcoder.com/practice/2c7f25d532aa4e20b67af9d3c93dc65f

function valueAtBit(num, bit) {
	var a = num.toString(2);
    var b = a.split("").reverse().join("");
    return b[bit - 1];
}