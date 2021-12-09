func lemonadeChange(bills []int) bool {
	counter1 := 0
	counter2 := 0
	for i := 0; i < len(bills); i++ {
		if bills[i] == 5 {
			counter1++
		} else if bills[i] == 10 {
			if counter1 == 0 {
				return false
			}
			counter1--
			counter2++
		} else {
			// 10+5
			if counter1 > 0 && counter2 > 0 {
				counter1--
				counter2--
			} else if counter1 >= 3 {
				counter1 -= 3
			} else {
				return false
			}
		}
	}
	return true
}