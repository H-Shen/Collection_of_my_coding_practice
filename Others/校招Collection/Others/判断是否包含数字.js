// https://www.nowcoder.com/practice/0fcb4eb9306d4bec837d0037fe39bcf7

function containsNumber(str) {
    var temp;
	for (var i = 0; i < str.length; i++) {
        temp = str[i].charCodeAt();
        if (temp >= 48 && temp <= 57) {
            return true;
        }
    }
    return false;
}