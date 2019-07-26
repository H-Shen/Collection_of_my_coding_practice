// https://www.nowcoder.com/practice/c141ec7458f244a1ba1bb334c71e0f27

function endsWithVowel(str) {
    var lastIdx = str.length - 1;
    var vowel = ['a','e','i','o','u','A','E','I','U','O'];
    for (var i = 0; i < vowel.length; i++) {
        if (str[lastIdx] === vowel[i]) {
            return true;
        }
    }
    return false;
}