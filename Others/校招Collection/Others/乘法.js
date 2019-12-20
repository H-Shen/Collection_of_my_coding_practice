// https://www.nowcoder.com/practice/6429776e4630435cbc3eeb36bdf41f83

function multiply(a, b) {
    var m = 0, s1 = a.toString(), s2 = b.toString();
    try {
        m += s1.split(".")[1].length
    } catch (e) {
    }
    try {
        m += s2.split(".")[1].length
    } catch (e) {
    }
    return Number(s1.replace(".", "")) * Number(s2.replace(".", "")) / Math.pow(10, m)
}