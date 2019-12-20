// https://www.nowcoder.com/practice/df84fa320cbe49d3b4a17516974b1136

function useArguments() {
	var s = 0;
    for (var i = 0; i < arguments.length; i++) {
        s += arguments[i];
    }
    return s;
}