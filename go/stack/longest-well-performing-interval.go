package stack

func longestWPI(hours []int) int {
	preSum :=[]int{0}
	sum := 0


	for _, h := range hours {
		if h > 8 {
			sum++
		}else {
			sum--
		}

		preSum = append(preSum, sum)


	}

	st := make([]int, 0)
	for idx, val := range preSum {
		if len(st) == 0 || preSum[st[len(st)-1]] > val {
			st = append(st, idx)
		}
	}

	maxWPI := 0
	for i := 0; i <len(st); i++ {
		idx := st[i]
		for j := len(preSum)-1; j > idx; j-- {
			if preSum[j] >preSum[idx] && j - idx  >maxWPI {
				maxWPI = j - idx
				break
			}
		}
	}

	return maxWPI
}