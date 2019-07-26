// https://www.nowcoder.com/practice/eb86f08c478749868a01861f5ddad28b

function matchesPattern(str) {
    var Regex_Pattern = /^\d\d\d\-\d\d\d\-\d\d\d\d$/;
    return Regex_Pattern.exec(str) != null;
}