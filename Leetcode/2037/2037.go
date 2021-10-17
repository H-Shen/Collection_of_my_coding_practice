func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func minMovesToSeat(seats []int, students []int) int {
	sort.Ints(seats)
	sort.Ints(students)
	ans := 0
	for i := 0; i < len(students); i++ {
		ans += abs(seats[i] - students[i])
	}
	return ans
}