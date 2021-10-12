/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	l := 1
	r := n
	var mid, temp int
	for l <= r {
		mid = l + ((r-l) >> 1)
		temp = guess(mid)
		if temp == 0 {
			return mid
		} else if temp > 0 {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return -1
}