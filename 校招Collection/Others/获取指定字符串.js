// https://www.nowcoder.com/practice/4ec56ad04a9a4402a01e50a390a8060a

function captureThreeNumbers(str) {
    var len = str.length;
    if (len < 3) {
        return false;
    }

    function isNumber(str) {
        var temp;
        for (var i = 0; i < str.length; i++) {
            temp = str[i].charCodeAt();
            if (temp >= 48 && temp <= 57) {
                return true;
            }
        }
        return false;
    }

    var s;
    for (var i = 0; i < len - 2; i++) {
        if (isNumber(str[i]) && isNumber(str[i + 1]) && isNumber(str[i + 2])) {
            s = str[i] + str[i + 1] + str[i + 2];
            return s;
        }
    }
    return false;
}