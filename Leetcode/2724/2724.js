/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    function cmp(a, b) {
        let l = fn(a)
        let r = fn(b)
        if (l < r) {
            return -1
        } else if (l > r) {
            return 1
        }
        return 0
    }
    return arr.sort(cmp)
};