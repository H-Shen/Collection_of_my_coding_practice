// https://www.nowcoder.com/practice/5ef31f11adf64d9fb18d74860e9ab873

function containsRepeatingLetter(str) {

    function isAlpha(str) {
        var temp;
        for (var i = 0; i < str.length; i++) {
            temp = str[i].charCodeAt();
            if ((temp >= 97 && temp <= 122) || (temp >= 65 && temp <= 90)) {
                return true;
            }
        }
        return false;
    }

    for (var i = 0; i < str.length - 1; i++) {
        if (isAlpha(str[i]) && isAlpha(str[i + 1]) && str[i] === str[i + 1]) {
            return true;
        }
    }
    return false;
}