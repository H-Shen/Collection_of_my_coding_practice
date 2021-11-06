const STEPS = 4

func turnRight(dir *int) {
    if (*dir) == 3 {
		*dir = 0
	} else {
        (*dir)++
	}
}

func move(dir int, i int, j int, newI *int, newJ *int)  {
	switch dir {
	case 0:
		i--
	case 1:
		j++
	case 2:
		i++
	case 3:
		j--
	}
	*newI = i
	*newJ = j
}

func numberOfCleanRooms(room [][]int) int {
	n := len(room)
	m := len(room[0])
	vis := make([][][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([][]bool, m)
		for j := 0; j < m; j++ {
			vis[i][j] = make([]bool, STEPS)
		}
	}
	visStep := make([][]bool, n)
	for i := 0; i < n; i++ {
		visStep[i] = make([]bool, m)
	}
	curI, curJ, dir := 0, 0, 1
	var newI, newJ int
	counter := 1
	visStep[curI][curJ] = true
	vis[curI][curJ][dir] = true
	for {
		move(dir, curI, curJ, &newI, &newJ)
		if newI >= 0 && newI < n && newJ >= 0 && newJ < m && room[newI][newJ] == 0 {
			if vis[newI][newJ][dir] {
				break
			}
			vis[newI][newJ][dir] = true
			if !visStep[newI][newJ] {
				visStep[newI][newJ] = true
				counter++
			}
            curI, curJ = newI, newJ
		} else {
			turnRight(&dir)
			if vis[curI][curJ][dir] {
				break
			}
			vis[curI][curJ][dir] = true
		}
	}
	return counter
}