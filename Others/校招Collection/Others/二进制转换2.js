// https://www.nowcoder.com/practice/7b74386695cc48349af37196f45e62a8

function convertToBinary(num) {
	var a = num.toString(2);
    var interval = 8 - a.length;
    var result = a;
    if (interval >= 8) {
        return result;
    }
	for (var i = 0; i < interval; i++) {
        result = "0" + result;
    }
    return result;
}