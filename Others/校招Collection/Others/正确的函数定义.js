// https://www.nowcoder.com/practice/a5de760a7cf24c0e890eb02eed34bc02

function functions(flag) {
    if (flag) {
        function getValue() { return 'a'; }
    }
    return getValue();
}